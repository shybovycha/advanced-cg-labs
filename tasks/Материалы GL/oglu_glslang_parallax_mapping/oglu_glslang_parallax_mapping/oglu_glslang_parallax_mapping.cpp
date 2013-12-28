//-----------------------------------------------------------------------------
//           Name: oglu_glslang_parallax_mapping.cpp
//         Author: Tristan Dean (twixn@twixn.com)
//  Last Modified: 02/27/06
//    Description: This sample demonstrates the usage of 'Parallax'
//                 mapping. Please note that this is simply a modification
//                 of an official CodeSampler.com sample.
//                 All changes will be marked with  a 'new' block.
//                 Press 'F1' to toggle parallax mapping.
//-----------------------------------------------------------------------------

// (Original Sample header)
//-----------------------------------------------------------------------------
//           Name: ogl_glslang_simple_vs2ps.cpp
//         Author: Kevin Harris (kevin@codesampler.com)
//  Last Modified: 03/03/04
//    Description: This sample demonstrates how to write vertex and fragment 
//                 shaders using OpenGL's new high-level shading language 
//                 GLslang.
//
//   Control Keys: F1 - Toggle usage of vertex and fragment shaders.
//
// Note: The fragment shader has been changed slightly from what the 
//       fixed-function pipeline does by default so you can see a noticeable 
//       change when toggling the shaders on and off. Instead of modulating 
//       the vertex color with the texture's texel, the fragment shader adds the 
//       two together, which causes the fragment shader to produce a brighter, 
//       washed-out image. This modification can be switched back in the fragment 
//       shader file.
//-----------------------------------------------------------------------------

#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <GL/glaux.h>
#include <mmsystem.h>
#include <assert.h>
#include "resource.h"

//-----------------------------------------------------------------------------
// FUNCTION POINTERS FOR OPENGL EXTENSIONS
//-----------------------------------------------------------------------------

// For convenience, this project ships with its own "glext.h" extension header 
// file. If you have trouble running this sample, it may be that this "glext.h" 
// file is defining something that your hardware doesn’t actually support. 
// Try recompiling the sample using your own local, vendor-specific "glext.h" 
// header file.

#include "glext.h"      // Sample's header file
//#include <GL/glext.h> // Your local header file

// GL_ARB_shader_objects
PFNGLCREATEPROGRAMOBJECTARBPROC  glCreateProgramObjectARB  = NULL;
PFNGLDELETEOBJECTARBPROC         glDeleteObjectARB         = NULL;
PFNGLUSEPROGRAMOBJECTARBPROC     glUseProgramObjectARB     = NULL;
PFNGLCREATESHADEROBJECTARBPROC   glCreateShaderObjectARB   = NULL;
PFNGLSHADERSOURCEARBPROC         glShaderSourceARB         = NULL;
PFNGLCOMPILESHADERARBPROC        glCompileShaderARB        = NULL;
PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB = NULL;
PFNGLATTACHOBJECTARBPROC         glAttachObjectARB         = NULL;
PFNGLGETINFOLOGARBPROC           glGetInfoLogARB           = NULL;
PFNGLLINKPROGRAMARBPROC          glLinkProgramARB          = NULL;
PFNGLGETUNIFORMLOCATIONARBPROC   glGetUniformLocationARB   = NULL;
PFNGLUNIFORM4FARBPROC            glUniform4fARB            = NULL;
PFNGLUNIFORM1IARBPROC            glUniform1iARB            = NULL;

//GL_ARB_multitexture
PFNGLACTIVETEXTUREPROC           glActiveTexture ;

//-----------------------------------------------------------------------------
// GLOBALS
//-----------------------------------------------------------------------------
HDC	      g_hDC       = NULL;
HGLRC     g_hRC       = NULL;
HWND      g_hWnd      = NULL;
HINSTANCE g_hInstance = NULL;
GLuint    g_textureID = 0;

GLhandleARB g_programObj;
GLhandleARB g_vertexShader;
GLhandleARB g_fragmentShader;
GLuint      g_location_testTexture;

///////////////////////////////////////////////////////////
// NEW - The Uniform handles.
// The Eye uniform is simply so that the shader knows where
// the camera is. 
// The Tangent and BiNormal will be explained when they
// are passed to the shader as uniforms (in 'setShaderConstants()').
// Also, we need a new texture. The 'HeightMap', which is
// just a grey-scale image used to determine height.
///////////////////////////////////////////////////////////

GLuint      g_location_eyePos;
GLuint      g_location_tangent;
GLuint      g_location_normal;
GLuint      g_location_binormal;
GLuint      g_location_heightTexture;
GLuint    g_heightMapID = 0;

bool g_bUseShaders = true;

float g_fSpinX = 0.0f;
float g_fSpinY = 0.0f;

// GL_T2F_C3F_V3F
struct Vertex
{
	float tu, tv;
	float r, g, b;
	float x, y, z;
};

Vertex g_quadVertices[] =
{
	// tu,  tv     r    g    b       x     y     z 
	{ 0.0f,0.0f,  1.0f,1.0f,1.0f, -1.0f,-1.0f, 0.0f },
	{ 1.0f,0.0f,  1.0f,1.0f,1.0f,  1.0f,-1.0f, 0.0f },
	{ 1.0f,1.0f,  1.0f,1.0f,1.0f,  1.0f, 1.0f, 0.0f },
	{ 0.0f,1.0f,  1.0f,1.0f,1.0f, -1.0f, 1.0f, 0.0f },
};


    

//-----------------------------------------------------------------------------
// PROTOTYPES
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE g_hInstance,HINSTANCE hPrevInstance, 
				   LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WindowProc(HWND g_hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void init(void);
void render(void);
void shutDown(void);
unsigned char *readShaderFile(const char *fileName);
void initShader(void);
void setShaderConstants(void);

//-----------------------------------------------------------------------------
// Name: WinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
int WINAPI WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR     lpCmdLine,
					int       nCmdShow )
{
	WNDCLASSEX winClass;
	MSG        uMsg;

    memset(&uMsg,0,sizeof(uMsg));

	winClass.lpszClassName = "MY_WINDOWS_CLASS";
	winClass.cbSize        = sizeof(WNDCLASSEX);
	winClass.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	winClass.lpfnWndProc   = WindowProc;
	winClass.hInstance     = hInstance;
    winClass.hIcon	       = LoadIcon(hInstance, (LPCTSTR)IDI_OPENGL_ICON);
    winClass.hIconSm	   = LoadIcon(hInstance, (LPCTSTR)IDI_OPENGL_ICON);
	winClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winClass.lpszMenuName  = NULL;
	winClass.cbClsExtra    = 0;
	winClass.cbWndExtra    = 0;
	
	if( !RegisterClassEx(&winClass) )
		return E_FAIL;

	g_hWnd = CreateWindowEx( NULL,"MY_WINDOWS_CLASS",
						    "OpenGL - Simple Parallax Mapping Using GLslang",
							WS_OVERLAPPEDWINDOW,
					 	    0,0, 640,480, NULL, NULL, g_hInstance, NULL );

	if( g_hWnd == NULL )
		return E_FAIL;

    ShowWindow( g_hWnd, nCmdShow );
    UpdateWindow( g_hWnd );

	init();
	initShader();

	while( uMsg.message != WM_QUIT )
	{
		if( PeekMessage( &uMsg, NULL, 0, 0, PM_REMOVE ) )
		{ 
			TranslateMessage( &uMsg );
			DispatchMessage( &uMsg );
		}
        else
		    render();
	}

	shutDown();

    UnregisterClass( "MY_WINDOWS_CLASS", g_hInstance );

	return uMsg.wParam;
}

//-----------------------------------------------------------------------------
// Name: WindowProc()
// Desc: The window's message handler
//-----------------------------------------------------------------------------
LRESULT CALLBACK WindowProc( HWND   g_hWnd, 
							 UINT   msg, 
							 WPARAM wParam, 
							 LPARAM lParam )
{
    static POINT ptLastMousePosit;
	static POINT ptCurrentMousePosit;
	static bool bMousing;
    
    switch( msg )
	{
        case WM_KEYDOWN:
		{
			switch( wParam )
			{
				case VK_ESCAPE:
					PostQuitMessage(0);
					break;

				case VK_F1:
					g_bUseShaders = !g_bUseShaders;
					break;
			}
		}
        break;

        case WM_LBUTTONDOWN:
		{
			ptLastMousePosit.x = ptCurrentMousePosit.x = LOWORD (lParam);
            ptLastMousePosit.y = ptCurrentMousePosit.y = HIWORD (lParam);
			bMousing = true;
		}
		break;

		case WM_LBUTTONUP:
		{
			bMousing = false;
		}
		break;

		case WM_MOUSEMOVE:
		{
			ptCurrentMousePosit.x = LOWORD (lParam);
			ptCurrentMousePosit.y = HIWORD (lParam);

			if( bMousing )
			{
				g_fSpinX -= (ptCurrentMousePosit.x - ptLastMousePosit.x);
				g_fSpinY -= (ptCurrentMousePosit.y - ptLastMousePosit.y);
			}
			
			ptLastMousePosit.x = ptCurrentMousePosit.x;
            ptLastMousePosit.y = ptCurrentMousePosit.y;
		}
		break;
		
		case WM_SIZE:
		{
			int nWidth  = LOWORD(lParam); 
			int nHeight = HIWORD(lParam);
			glViewport(0, 0, nWidth, nHeight);

			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
			gluPerspective( 45.0, (GLdouble)nWidth / (GLdouble)nHeight, 0.1, 100.0);
		}
		break;

		case WM_CLOSE:
		{
			PostQuitMessage(0);	
		}

        case WM_DESTROY:
		{
            PostQuitMessage(0);
		}
        break;
		
		default:
		{
			return DefWindowProc( g_hWnd, msg, wParam, lParam );
		}
		break;
	}

	return 0;
}

//-----------------------------------------------------------------------------
// Name: init()
// Desc: 
//-----------------------------------------------------------------------------
void init( void )
{
	GLuint PixelFormat;

	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW |PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 16;
    pfd.cDepthBits = 16;
	
	g_hDC = GetDC( g_hWnd );
	PixelFormat = ChoosePixelFormat( g_hDC, &pfd );
	SetPixelFormat( g_hDC, PixelFormat, &pfd);
	g_hRC = wglCreateContext( g_hDC );
	wglMakeCurrent( g_hDC, g_hRC );

	glEnable( GL_TEXTURE_2D );
	glEnable( GL_DEPTH_TEST );

	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45.0f, 640.0f / 480.0f, 0.1f, 100.0f);

	//
	// Create a texture to test out our fragment shader...
	//

	AUX_RGBImageRec *pTextureImage = auxDIBImageLoad( ".\\wall1.bmp" );

	if( pTextureImage != NULL )
	{
		glGenTextures( 1, &g_textureID );

		glBindTexture(GL_TEXTURE_2D, g_textureID);

		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);
	}

	if( pTextureImage )
	{
		if( pTextureImage->data )
			free( pTextureImage->data );

		free( pTextureImage );
	}
	
    ///////////////////////////////////////////////////////////
    // NEW - Loading the height map.
    ///////////////////////////////////////////////////////////
    pTextureImage = auxDIBImageLoad( ".\\BUMPwall1.bmp" );

	if( pTextureImage != NULL )
	{
		glGenTextures( 1, &g_heightMapID );

		glBindTexture(GL_TEXTURE_2D, g_heightMapID);

		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);
	}

	if( pTextureImage )
	{
		if( pTextureImage->data )
			free( pTextureImage->data );

		free( pTextureImage );
	}
	
}

//-----------------------------------------------------------------------------
// Name: readShaderFile()
// Desc: 
//-----------------------------------------------------------------------------
unsigned char *readShaderFile( const char *fileName )
{
    FILE *file = fopen( fileName, "r" );

    if( file == NULL )
    {
        MessageBox( NULL, "Cannot open shader file!", "ERROR",
            MB_OK | MB_ICONEXCLAMATION );
		return 0;
    }

    struct _stat fileStats;

    if( _stat( fileName, &fileStats ) != 0 )
    {
        MessageBox( NULL, "Cannot get file stats for shader file!", "ERROR",
                    MB_OK | MB_ICONEXCLAMATION );
        return 0;
    }

    unsigned char *buffer = new unsigned char[fileStats.st_size];

	int bytes = fread( buffer, 1, fileStats.st_size, file );

    buffer[bytes] = 0;

	fclose( file );

	return buffer;
}

//-----------------------------------------------------------------------------
// Name: initShader()
// Desc: Assemble the shader 
//-----------------------------------------------------------------------------
void initShader( void )
{
	//
	// If the required extension is present, get the addresses of its 
	// functions that we wish to use...
	//

	char *ext = (char*)glGetString( GL_EXTENSIONS );

    if( strstr( ext, "GL_ARB_shading_language_100" ) == NULL )
    {
        //This extension string indicates that the OpenGL Shading Language,
        // version 1.00, is supported.
        MessageBox(NULL,"GL_ARB_shading_language_100 extension was not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
        return;
    }

    if( strstr( ext, "GL_ARB_shader_objects" ) == NULL )
    {
        MessageBox(NULL,"GL_ARB_shader_objects extension was not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
        return;
    }
    else
    {
        glCreateProgramObjectARB  = (PFNGLCREATEPROGRAMOBJECTARBPROC)wglGetProcAddress("glCreateProgramObjectARB");
        glDeleteObjectARB         = (PFNGLDELETEOBJECTARBPROC)wglGetProcAddress("glDeleteObjectARB");
        glUseProgramObjectARB     = (PFNGLUSEPROGRAMOBJECTARBPROC)wglGetProcAddress("glUseProgramObjectARB");
        glCreateShaderObjectARB   = (PFNGLCREATESHADEROBJECTARBPROC)wglGetProcAddress("glCreateShaderObjectARB");
        glShaderSourceARB         = (PFNGLSHADERSOURCEARBPROC)wglGetProcAddress("glShaderSourceARB");
        glCompileShaderARB        = (PFNGLCOMPILESHADERARBPROC)wglGetProcAddress("glCompileShaderARB");
        glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
        glAttachObjectARB         = (PFNGLATTACHOBJECTARBPROC)wglGetProcAddress("glAttachObjectARB");
        glGetInfoLogARB           = (PFNGLGETINFOLOGARBPROC)wglGetProcAddress("glGetInfoLogARB");
        glLinkProgramARB          = (PFNGLLINKPROGRAMARBPROC)wglGetProcAddress("glLinkProgramARB");
        glGetUniformLocationARB   = (PFNGLGETUNIFORMLOCATIONARBPROC)wglGetProcAddress("glGetUniformLocationARB");
        glUniform4fARB            = (PFNGLUNIFORM4FARBPROC)wglGetProcAddress("glUniform4fARB");
		glUniform1iARB            = (PFNGLUNIFORM1IARBPROC)wglGetProcAddress("glUniform1iARB");

        if( !glCreateProgramObjectARB || !glDeleteObjectARB || !glUseProgramObjectARB ||
            !glCreateShaderObjectARB || !glCreateShaderObjectARB || !glCompileShaderARB || 
            !glGetObjectParameterivARB || !glAttachObjectARB || !glGetInfoLogARB || 
            !glLinkProgramARB || !glGetUniformLocationARB || !glUniform4fARB ||
			!glUniform1iARB )
        {
            MessageBox(NULL,"One or more GL_ARB_shader_objects functions were not found",
                "ERROR",MB_OK|MB_ICONEXCLAMATION);
            return;
        }
    }
    
    // Check for multitexture support.
    if(strstr(ext, "GL_ARB_multitexture"))
    {
        glActiveTexture		= (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
    }else{
        MessageBox(NULL,"One or more GL_ARB_shader_objects functions were not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
        return;
    }

    const char *shaderStrings[1];
    int nResult;
    char str[4096];

	g_programObj = glCreateProgramObjectARB();

	//
	// Vertex shader
	//

	unsigned char *shader_assembly = readShaderFile( "vertex_shader.vert" );

    g_vertexShader = glCreateShaderObjectARB( GL_VERTEX_SHADER_ARB );
    shaderStrings[0] = (char*)shader_assembly;
    glShaderSourceARB( g_vertexShader, 1, shaderStrings, NULL );
    glCompileShaderARB( g_vertexShader);
    glGetObjectParameterivARB( g_vertexShader, GL_OBJECT_COMPILE_STATUS_ARB, &nResult );

    if( nResult )
        glAttachObjectARB( g_programObj, g_vertexShader );
	else
	{
		glGetInfoLogARB(g_vertexShader, sizeof(str), NULL, str);
		MessageBox( NULL, str, "Vertex Shader Compile Error", MB_OK|MB_ICONEXCLAMATION );
	}

	//
	// Fragment shader
	//

	delete shader_assembly;
	shader_assembly = readShaderFile( "fragment_shader.frag" );

    g_fragmentShader = glCreateShaderObjectARB( GL_FRAGMENT_SHADER_ARB );
    shaderStrings[0] = (char*)shader_assembly;
    glShaderSourceARB( g_fragmentShader, 1, shaderStrings, NULL );
    glCompileShaderARB( g_fragmentShader );
    glGetObjectParameterivARB( g_fragmentShader, GL_OBJECT_COMPILE_STATUS_ARB, &nResult );

    if( nResult )
        glAttachObjectARB( g_programObj, g_fragmentShader );
	else
	{
		glGetInfoLogARB( g_fragmentShader, sizeof(str), NULL, str );
		MessageBox( NULL, str, "Fragment Shader Compile Error", MB_OK|MB_ICONEXCLAMATION );
	}

    glLinkProgramARB( g_programObj );
    glGetObjectParameterivARB( g_programObj, GL_OBJECT_LINK_STATUS_ARB, &nResult );

    if( !nResult )
	{
		glGetInfoLogARB( g_programObj, sizeof(str), NULL, str );
		MessageBox( NULL, str, "Linking Error", MB_OK|MB_ICONEXCLAMATION );
	}

	delete shader_assembly;

	//
	// Locate some parameters by name so we can set them later...
	//

	g_location_testTexture = glGetUniformLocationARB( g_programObj, "testTexture" );
	
	///////////////////////////////////////////////////////////
    // NEW - Retrieving more Uniform locations.
	///////////////////////////////////////////////////////////
	g_location_eyePos = glGetUniformLocationARB( g_programObj, "Eye" );
	g_location_tangent = glGetUniformLocationARB( g_programObj, "Tangent" );
	g_location_normal = glGetUniformLocationARB( g_programObj, "Normal" );
	g_location_binormal = glGetUniformLocationARB( g_programObj, "BiNormal" );
    g_location_heightTexture = glGetUniformLocationARB( g_programObj, "HeightTexture" );
	
	
}

//-----------------------------------------------------------------------------
// Name: shutDown()
// Desc: 
//-----------------------------------------------------------------------------
void shutDown( void )
{
    glDeleteObjectARB( g_vertexShader );
    glDeleteObjectARB( g_fragmentShader );
    glDeleteObjectARB( g_programObj );

	if( g_hRC != NULL )
	{
		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( g_hRC );
		g_hRC = NULL;							
	}

	if( g_hRC != NULL )
	{
		ReleaseDC( g_hWnd, g_hDC );
		g_hDC = NULL;
	}
}

//-----------------------------------------------------------------------------
// Name: setShaderConstants()
// Desc: 
//-----------------------------------------------------------------------------
void setShaderConstants( void )
{
	glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
	glTranslatef( 0.0f, 0.0f, -4.0f );
    glRotatef( -g_fSpinY, 1.0f, 0.0f, 0.0f );
    glRotatef( -g_fSpinX, 0.0f, 1.0f, 0.0f );

	//
	// Set constants for the fragment shader...
	//

	// Identify the texture to use
	if( g_location_testTexture != -1 )
		glUniform1iARB( g_location_testTexture, 0);//g_textureID );
		
		
	///////////////////////////////////////////////////////////
    // NEW - Sending the Eye position and height map
	///////////////////////////////////////////////////////////
	
	
	if( g_location_heightTexture != -1 )
		glUniform1iARB( g_location_heightTexture, 1);//g_textureID );
	
	// NOTE: this is not the best way to input the eye position.
	// The best way is to inversly transform the eye position by
	// the model matrix here, and send the transformed position to the
	// shader. However, we will do it this way now to avoid adding matrix code.
	if( g_location_eyePos != -1 )
		glUniform4fARB( g_location_eyePos, 0.0f, 0.0f, 0.0f, 1.0f );
				
	///////////////////////////////////////////////////////////
    // NEW - We will need a tangent vector and a BiNormal vector
    // for this sample. This is essentially just to convert
    // the eye position and the light position into 'tangent' space
    // ie, relative to the texture placement of the triangle.
    // NOTE: The values below are specific to this sample,
    // it is out of the scope of this sample to calculate tangents
    // and binormals.
    ///////////////////////////////////////////////////////////
	
	if( g_location_tangent != -1 )
		glUniform4fARB( g_location_tangent, 1.0f, 0.0f, 0.0f, 0.0f );
		
	if( g_location_normal != -1 )
		glUniform4fARB( g_location_normal, 0.0f, 0.0f, 1.0f, 0.0f );
		
	if( g_location_binormal != -1 )
		glUniform4fARB( g_location_binormal, 0.0f, 1.0f, 0.0f, 0.0f );
}

//-----------------------------------------------------------------------------
// Name: render()
// Desc: 
//-----------------------------------------------------------------------------
void render( void )
{
	// Clear the screen and the depth buffer
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	if( g_bUseShaders == true )
	{
		//
		// Use vertex and fragment shaders...
		//


		glUseProgramObjectARB( g_programObj );
        glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, g_textureID);
        glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, g_heightMapID);
        glActiveTexture(GL_TEXTURE0);
		setShaderConstants();

		glInterleavedArrays( GL_T2F_C3F_V3F, 0, g_quadVertices );
		glDrawArrays( GL_QUADS, 0, 4 );

		glUseProgramObjectARB( NULL );
	}
	else
	{
		//
		// Render the normal way...
		//

		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
		glTranslatef( 0.0f, 0.0f, -4.0f );
		glRotatef( -g_fSpinY, 1.0f, 0.0f, 0.0f );
		glRotatef( -g_fSpinX, 0.0f, 1.0f, 0.0f );

		glBindTexture(GL_TEXTURE_2D, g_textureID);
		glInterleavedArrays( GL_T2F_C3F_V3F, 0, g_quadVertices );
		glDrawArrays( GL_QUADS, 0, 4 );
	}

	SwapBuffers( g_hDC );
}
