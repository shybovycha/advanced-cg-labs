/*
 * glarb.c
 * 
 * 
 *
 */

#include "glextapi.h"


/////////////////////////////////////////////////////////////////////

#ifndef GLARB_GET_PROCADDRESS
# ifdef WIN32
#  define GLARB_GET_PROCADDRESS	wglGetProcAddress
# else
#  define GLARB_GET_PROCADDRESS	glxGetProcAddressARB
# endif
#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_multitexture

void glActiveTextureARB (GLenum texture)
{
	static PFNGLACTIVETEXTUREARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLACTIVETEXTUREARBPROC) GLARB_GET_PROCADDRESS( "glActiveTextureARB" );
	if( pfngl ) (*pfngl)( texture );
}
void glClientActiveTextureARB (GLenum texture)
{
	static PFNGLCLIENTACTIVETEXTUREARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLCLIENTACTIVETEXTUREARBPROC) GLARB_GET_PROCADDRESS( "glClientActiveTextureARB" );
	if( pfngl ) (*pfngl)( texture );
}
void glMultiTexCoord1dARB (GLenum target, GLdouble s)
{
	static PFNGLMULTITEXCOORD1DARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD1DARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord1dARB" );
	if( pfngl ) (*pfngl)( target, s );
}
void glMultiTexCoord1dvARB (GLenum target, const GLdouble *v)
{
	static PFNGLMULTITEXCOORD1DVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD1DVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord1dvARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord1fARB (GLenum target, GLfloat s)
{
	static PFNGLMULTITEXCOORD1FARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD1FARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord1fARB" );
	if( pfngl ) (*pfngl)( target, s );
}
void glMultiTexCoord1fvARB (GLenum target, const GLfloat *v)
{
	static PFNGLMULTITEXCOORD1FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD1FVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord1fvARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord1iARB (GLenum target, GLint s)
{
	static PFNGLMULTITEXCOORD1IARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD1IARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord1iARB" );
	if( pfngl ) (*pfngl)( target, s );
}
void glMultiTexCoord1ivARB (GLenum target, const GLint *v)
{
	static PFNGLMULTITEXCOORD1IVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD1IVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord1ivARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord1sARB (GLenum target, GLshort s)
{
	static PFNGLMULTITEXCOORD1SARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD1SARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord1sARB" );
	if( pfngl ) (*pfngl)( target, s );
}
void glMultiTexCoord1svARB (GLenum target, const GLshort *v)
{
	static PFNGLMULTITEXCOORD1SVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD1SVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord1svARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord2dARB (GLenum target, GLdouble s, GLdouble t)
{
	static PFNGLMULTITEXCOORD2DARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD2DARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord2dARB" );
	if( pfngl ) (*pfngl)( target, s, t );
}
void glMultiTexCoord2dvARB (GLenum target, const GLdouble *v)
{
	static PFNGLMULTITEXCOORD2DVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD2DVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord2dvARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord2fARB (GLenum target, GLfloat s, GLfloat t)
{
	static PFNGLMULTITEXCOORD2FARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD2FARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord2fARB" );
	if( pfngl ) (*pfngl)( target, s, t );
}
void glMultiTexCoord2fvARB (GLenum target, const GLfloat *v)
{
	static PFNGLMULTITEXCOORD2FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD2FVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord2fvARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord2iARB (GLenum target, GLint s, GLint t)
{
	static PFNGLMULTITEXCOORD2IARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD2IARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord2iARB" );
	if( pfngl ) (*pfngl)( target, s, t );
}
void glMultiTexCoord2ivARB (GLenum target, const GLint *v)
{
	static PFNGLMULTITEXCOORD2IVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD2IVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord2ivARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord2sARB (GLenum target, GLshort s, GLshort t)
{
	static PFNGLMULTITEXCOORD2SARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD2SARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord2sARB" );
	if( pfngl ) (*pfngl)( target, s, t );
}
void glMultiTexCoord2svARB (GLenum target, const GLshort *v)
{
	static PFNGLMULTITEXCOORD2SVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD2SVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord2svARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord3dARB (GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
	static PFNGLMULTITEXCOORD3DARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD3DARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord3dARB" );
	if( pfngl ) (*pfngl)( target, s, t, r );
}
void glMultiTexCoord3dvARB (GLenum target, const GLdouble *v)
{
	static PFNGLMULTITEXCOORD3DVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD3DVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord3dvARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord3fARB (GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
	static PFNGLMULTITEXCOORD3FARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD3FARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord3fARB" );
	if( pfngl ) (*pfngl)( target, s, t, r );
}
void glMultiTexCoord3fvARB (GLenum target, const GLfloat *v)
{
	static PFNGLMULTITEXCOORD3FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD3FVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord3fvARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord3iARB (GLenum target, GLint s, GLint t, GLint r)
{
	static PFNGLMULTITEXCOORD3IARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD3IARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord3iARB" );
	if( pfngl ) (*pfngl)( target, s, t, r );
}
void glMultiTexCoord3ivARB (GLenum target, const GLint *v)
{
	static PFNGLMULTITEXCOORD3IVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD3IVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord3ivARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord3sARB (GLenum target, GLshort s, GLshort t, GLshort r)
{
	static PFNGLMULTITEXCOORD3SARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD3SARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord3sARB" );
	if( pfngl ) (*pfngl)( target, s, t, r );
}
void glMultiTexCoord3svARB (GLenum target, const GLshort *v)
{
	static PFNGLMULTITEXCOORD3SVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD3SVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord3svARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord4dARB (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
	static PFNGLMULTITEXCOORD4DARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD4DARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord4dARB" );
	if( pfngl ) (*pfngl)( target, s, t, r, q );
}
void glMultiTexCoord4dvARB (GLenum target, const GLdouble *v)
{
	static PFNGLMULTITEXCOORD4DVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD4DVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord4dvARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord4fARB (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	static PFNGLMULTITEXCOORD4FARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD4FARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord4fARB" );
	if( pfngl ) (*pfngl)( target, s, t, r, q );
}
void glMultiTexCoord4fvARB (GLenum target, const GLfloat *v)
{
	static PFNGLMULTITEXCOORD4FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD4FVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord4fvARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord4iARB (GLenum target, GLint s, GLint t, GLint r, GLint q)
{
	static PFNGLMULTITEXCOORD4IARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD4IARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord4iARB" );
	if( pfngl ) (*pfngl)( target, s, t, r, q );
}
void glMultiTexCoord4ivARB (GLenum target, const GLint *v)
{
	static PFNGLMULTITEXCOORD4IVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD4IVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord4ivARB" );
	if( pfngl ) (*pfngl)( target, v );
}
void glMultiTexCoord4sARB (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
	static PFNGLMULTITEXCOORD4SARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD4SARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord4sARB" );
	if( pfngl ) (*pfngl)( target, s, t, r, q );
}
void glMultiTexCoord4svARB (GLenum target, const GLshort *v)
{
	static PFNGLMULTITEXCOORD4SVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMULTITEXCOORD4SVARBPROC) GLARB_GET_PROCADDRESS( "glMultiTexCoord4svARB" );
	if( pfngl ) (*pfngl)( target, v );
}

//#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_vertex_buffer_object

void glBindBufferARB (GLenum target, GLuint buffer)
{
	static PFNGLBINDBUFFERARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLBINDBUFFERARBPROC) GLARB_GET_PROCADDRESS( "glBindBufferARB" );
	if( pfngl ) (*pfngl)( target, buffer );
}

void glDeleteBuffersARB (GLsizei n, const GLuint *buffers)
{
	static PFNGLDELETEBUFFERSARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLDELETEBUFFERSARBPROC) GLARB_GET_PROCADDRESS( "glDeleteBuffersARB" );
	if( pfngl ) (*pfngl)( n, buffers );
}

void glGenBuffersARB (GLsizei n, GLuint *buffers)
{
	static PFNGLGENBUFFERSARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGENBUFFERSARBPROC) GLARB_GET_PROCADDRESS( "glGenBuffersARB" );
	if( pfngl ) (*pfngl)( n, buffers );
}

GLboolean glIsBufferARB (GLuint buffer)
{
	static PFNGLISBUFFERARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLISBUFFERARBPROC) GLARB_GET_PROCADDRESS( "glIsBufferARB" );
	return pfngl ? (*pfngl)( buffer ) : 0;
}

void glBufferDataARB (GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage)
{
	static PFNGLBUFFERDATAARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLBUFFERDATAARBPROC) GLARB_GET_PROCADDRESS( "glBufferDataARB" );
	if( pfngl ) (*pfngl)( target, size, data, usage );
}

void glBufferSubDataARB (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data)
{
	static PFNGLBUFFERSUBDATAARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLBUFFERSUBDATAARBPROC) GLARB_GET_PROCADDRESS( "glBufferSubDataARB" );
	if( pfngl ) (*pfngl)( target, offset, size, data );
}

void glGetBufferSubDataARB (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data)
{
	static PFNGLGETBUFFERSUBDATAARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETBUFFERSUBDATAARBPROC) GLARB_GET_PROCADDRESS( "glGetBufferSubDataARB" );
	if( pfngl ) (*pfngl)( target, offset, size, data );
}

GLvoid* glMapBufferARB (GLenum target, GLenum access)
{
	static PFNGLMAPBUFFERARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLMAPBUFFERARBPROC) GLARB_GET_PROCADDRESS( "glMapBufferARB" );
	return pfngl ? (*pfngl)( target, access ) : NULL;
}

GLboolean glUnmapBufferARB (GLenum target)
{
	static PFNGLUNMAPBUFFERARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNMAPBUFFERARBPROC) GLARB_GET_PROCADDRESS( "glUnmapBufferARB" );
	return pfngl ? (*pfngl)( target ) : 0;
}

void glGetBufferParameterivARB (GLenum target, GLenum pname, GLint *params)
{
	static PFNGLGETBUFFERPARAMETERIVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETBUFFERPARAMETERIVARBPROC) GLARB_GET_PROCADDRESS( "glGetBufferParameterivARB" );
	if( pfngl ) (*pfngl)( target, pname, params );
}

void glGetBufferPointervARB (GLenum target, GLenum pname, GLvoid* *params)
{
	static PFNGLGETBUFFERPOINTERVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETBUFFERPOINTERVARBPROC) GLARB_GET_PROCADDRESS( "glGetBufferPointervARB" );
	if( pfngl ) (*pfngl)( target, pname, params );
}

//#endif

/////////////////////////////////////////////////////////////////////

#ifdef GL_ARB_shader_objects

void glDeleteObjectARB(GLhandleARB obj)
{
	static PFNGLDELETEOBJECTARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLDELETEOBJECTARBPROC) GLARB_GET_PROCADDRESS("glDeleteObjectARB");
	if( pfngl ) (*pfngl)(obj);
}

GLhandleARB glGetHandleARB(GLenum pname)
{
	static PFNGLGETHANDLEARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETHANDLEARBPROC) GLARB_GET_PROCADDRESS("glGetHandleARB");
	return pfngl ? (*pfngl)(pname) : 0;
} 

void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj)
{
	static PFNGLDETACHOBJECTARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLDETACHOBJECTARBPROC) GLARB_GET_PROCADDRESS("glDetachObjectARB");
	if( pfngl ) (*pfngl)(containerObj, attachedObj);
}

GLhandleARB glCreateShaderObjectARB(GLenum shaderType)
{
	static PFNGLCREATESHADEROBJECTARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLCREATESHADEROBJECTARBPROC) GLARB_GET_PROCADDRESS("glCreateShaderObjectARB");
	return pfngl ? (*pfngl)(shaderType) : 0;
}
 
void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB* *string, const GLint *length)
{
	static PFNGLSHADERSOURCEARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLSHADERSOURCEARBPROC) GLARB_GET_PROCADDRESS("glShaderSourceARB");
	if( pfngl ) (*pfngl)(shaderObj, count, string, length);
}
 
void glCompileShaderARB(GLhandleARB shaderObj)
{
	static PFNGLCOMPILESHADERARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLCOMPILESHADERARBPROC) GLARB_GET_PROCADDRESS("glCompileShaderARB");
	if( pfngl ) (*pfngl)(shaderObj);
}
 
GLhandleARB glCreateProgramObjectARB(void)
{
	static PFNGLCREATEPROGRAMOBJECTARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLCREATEPROGRAMOBJECTARBPROC) GLARB_GET_PROCADDRESS("glCreateProgramObjectARB");
	return pfngl ? (*pfngl)() : 0;
}
 
void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj)
{
	static PFNGLATTACHOBJECTARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLATTACHOBJECTARBPROC) GLARB_GET_PROCADDRESS("glAttachObjectARB");
	if( pfngl ) (*pfngl)(containerObj, obj);
}
 
void glLinkProgramARB(GLhandleARB programObj)
{
	static PFNGLLINKPROGRAMARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLLINKPROGRAMARBPROC) GLARB_GET_PROCADDRESS("glLinkProgramARB");
	if( pfngl ) (*pfngl)(programObj);
}
 
void glUseProgramObjectARB(GLhandleARB programObj)
{
	static PFNGLUSEPROGRAMOBJECTARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUSEPROGRAMOBJECTARBPROC) GLARB_GET_PROCADDRESS("glUseProgramObjectARB");
	if( pfngl ) (*pfngl)(programObj);
}
 
void glValidateProgramARB(GLhandleARB programObj)
{
	static PFNGLVALIDATEPROGRAMARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVALIDATEPROGRAMARBPROC) GLARB_GET_PROCADDRESS("glValidateProgramARB");
	if( pfngl ) (*pfngl)(programObj);
}
 
void glUniform1fARB(GLint location, GLfloat v0)
{
	static PFNGLUNIFORM1FARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM1FARBPROC) GLARB_GET_PROCADDRESS("glUniform1fARB");
	if( pfngl ) (*pfngl)(location, v0);
}
 
void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1)
{
	static PFNGLUNIFORM2FARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM2FARBPROC) GLARB_GET_PROCADDRESS("glUniform2fARB");
	if( pfngl ) (*pfngl)(location, v0, v1);
}
 
void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	static PFNGLUNIFORM3FARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM3FARBPROC) GLARB_GET_PROCADDRESS("glUniform3fARB");
	if( pfngl ) (*pfngl)(location, v0, v1, v2);
}
 
void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	static PFNGLUNIFORM4FARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM4FARBPROC) GLARB_GET_PROCADDRESS("glUniform4fARB");
	if( pfngl ) (*pfngl)(location, v0, v1, v2, v3);
}
 
void glUniform1iARB(GLint location, GLint v0)
{
	static PFNGLUNIFORM1IARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM1IARBPROC) GLARB_GET_PROCADDRESS("glUniform1iARB");
	if( pfngl ) (*pfngl)(location, v0);
}
 
void glUniform2iARB(GLint location, GLint v0, GLint v1)
{
	static PFNGLUNIFORM2IARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM2IARBPROC) GLARB_GET_PROCADDRESS("glUniform2iARB");
	if( pfngl ) (*pfngl)(location, v0, v1);
}
 
void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2)
{
	static PFNGLUNIFORM3IARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM3IARBPROC) GLARB_GET_PROCADDRESS("glUniform3iARB");
	if( pfngl ) (*pfngl)(location, v0, v1, v2);
}
 
void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	static PFNGLUNIFORM4IARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM4IARBPROC) GLARB_GET_PROCADDRESS("glUniform4iARB");
	if( pfngl ) (*pfngl)(location, v0, v1, v2, v3);
}
 
void glUniform1fvARB(GLint location, GLsizei count, const GLfloat *value)
{
	static PFNGLUNIFORM1FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM1FVARBPROC) GLARB_GET_PROCADDRESS("glUniform1fvARB");
	if( pfngl ) (*pfngl)(location, count, value);
}
 
void glUniform2fvARB(GLint location, GLsizei count, const GLfloat *value)
{
	static PFNGLUNIFORM2FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM2FVARBPROC) GLARB_GET_PROCADDRESS("glUniform2fvARB");
	if( pfngl ) (*pfngl)(location, count, value);
}
 
void glUniform3fvARB(GLint location, GLsizei count, const GLfloat *value)
{
	static PFNGLUNIFORM3FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM3FVARBPROC) GLARB_GET_PROCADDRESS("glUniform3fvARB");
	if( pfngl ) (*pfngl)(location, count, value);
}
 
void glUniform4fvARB(GLint location, GLsizei count, const GLfloat *value)
{
	static PFNGLUNIFORM4FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM4FVARBPROC) GLARB_GET_PROCADDRESS("glUniform4fvARB");
	if( pfngl ) (*pfngl)(location, count, value);
}
 
void glUniform1ivARB(GLint location, GLsizei count, const GLint *value)
{
	static PFNGLUNIFORM1IVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM1IVARBPROC) GLARB_GET_PROCADDRESS("glUniform1ivARB");
	if( pfngl ) (*pfngl)(location, count, value);
}
 
void glUniform2ivARB(GLint location, GLsizei count, const GLint *value)
{
	static PFNGLUNIFORM2IVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM2IVARBPROC) GLARB_GET_PROCADDRESS("glUniform2ivARB");
	if( pfngl ) (*pfngl)(location, count, value);
}
 
void glUniform3ivARB(GLint location, GLsizei count, const GLint *value)
{
	static PFNGLUNIFORM3IVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM3IVARBPROC) GLARB_GET_PROCADDRESS("glUniform3ivARB");
	if( pfngl ) (*pfngl)(location, count, value);
}
 
void glUniform4ivARB(GLint location, GLsizei count, const GLint *value)
{
	static PFNGLUNIFORM4IVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORM4IVARBPROC) GLARB_GET_PROCADDRESS("glUniform4ivARB");
	if( pfngl ) (*pfngl)(location, count, value);
}
 
void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	static PFNGLUNIFORMMATRIX2FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORMMATRIX2FVARBPROC) GLARB_GET_PROCADDRESS("glUniformMatrix2fvARB");
	if( pfngl ) (*pfngl)(location, count, transpose, value);
}
 
void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	static PFNGLUNIFORMMATRIX3FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORMMATRIX3FVARBPROC) GLARB_GET_PROCADDRESS("glUniformMatrix3fvARB");
	if( pfngl ) (*pfngl)(location, count, transpose, value);
}
 
void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	static PFNGLUNIFORMMATRIX4FVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLUNIFORMMATRIX4FVARBPROC) GLARB_GET_PROCADDRESS("glUniformMatrix4fvARB");
	if( pfngl ) (*pfngl)(location, count, transpose, value);
}
 
void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat *params)
{
	static PFNGLGETOBJECTPARAMETERFVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETOBJECTPARAMETERFVARBPROC) GLARB_GET_PROCADDRESS("glGetObjectParameterfvARB");
	if( pfngl ) (*pfngl)(obj, pname, params);
}
 
void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint *params)
{
	static PFNGLGETOBJECTPARAMETERIVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETOBJECTPARAMETERIVARBPROC) GLARB_GET_PROCADDRESS("glGetObjectParameterivARB");
	if( pfngl ) (*pfngl)(obj, pname, params);
}
 
void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog)
{
	static PFNGLGETINFOLOGARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETINFOLOGARBPROC) GLARB_GET_PROCADDRESS("glGetInfoLogARB");
	if( pfngl ) (*pfngl)(obj, maxLength, length, infoLog);
}
 
void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj)
{
	static PFNGLGETATTACHEDOBJECTSARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETATTACHEDOBJECTSARBPROC) GLARB_GET_PROCADDRESS("glGetAttachedObjectsARB");
	if( pfngl ) (*pfngl)(containerObj, maxCount, count, obj);
}
 
GLint glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB *name)
{
	static PFNGLGETUNIFORMLOCATIONARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETUNIFORMLOCATIONARBPROC) GLARB_GET_PROCADDRESS("glGetUniformLocationARB");
	return pfngl ? (*pfngl)(programObj, name) : 0;
}
 
void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name)
{
	static PFNGLGETACTIVEUNIFORMARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETACTIVEUNIFORMARBPROC) GLARB_GET_PROCADDRESS("glGetActiveUniformARB");
	if( pfngl ) (*pfngl)(programObj, index, maxLength, length, size, type, name);
}
 
void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat *params)
{
	static PFNGLGETUNIFORMFVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETUNIFORMFVARBPROC) GLARB_GET_PROCADDRESS("glGetUniformfvARB");
	if( pfngl ) (*pfngl)(programObj, location, params);
}
 
void glGetUniformivARB(GLhandleARB obj, GLint location, GLint *params)
{
	static PFNGLGETUNIFORMIVARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETUNIFORMIVARBPROC) GLARB_GET_PROCADDRESS("glGetUniformivARB");
	if( pfngl ) (*pfngl)(obj, location, params);
}
 
void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source)
{
	static PFNGLGETSHADERSOURCEARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETSHADERSOURCEARBPROC) GLARB_GET_PROCADDRESS("glGetShaderSourceARB");
	if( pfngl ) (*pfngl)(obj, maxLength, length, source);
}

#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_vertex_shader

void glDisableVertexAttribArrayARB(GLuint index)
{
	static PFNGLDISABLEVERTEXATTRIBARRAYPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) GLARB_GET_PROCADDRESS("glDisableVertexAttribArrayARB");
	if( pfngl ) (*pfngl)(index);
}
void glEnableVertexAttribArrayARB(GLuint index)
{
	static PFNGLENABLEVERTEXATTRIBARRAYPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLENABLEVERTEXATTRIBARRAYPROC) GLARB_GET_PROCADDRESS("glEnableVertexAttribArrayARB");
	if( pfngl ) (*pfngl)(index);
}

void glBindAttribLocationARB (GLhandleARB programObj, GLuint index, const GLcharARB *name)
{
	static PFNGLBINDATTRIBLOCATIONARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLBINDATTRIBLOCATIONARBPROC) GLARB_GET_PROCADDRESS("glBindAttribLocationARB");
	if( pfngl ) (*pfngl)(programObj, index, name);
}
void glGetActiveAttribARB (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name)
{
	static PFNGLGETACTIVEATTRIBARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETACTIVEATTRIBARBPROC) GLARB_GET_PROCADDRESS("glGetActiveAttribARB");
	if( pfngl ) (*pfngl)(programObj, index, maxLength, length, size, type, name);
}
GLint glGetAttribLocationARB (GLhandleARB programObj, const GLcharARB *name)
{
	static PFNGLGETATTRIBLOCATIONARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETATTRIBLOCATIONARBPROC) GLARB_GET_PROCADDRESS("glGetAttribLocationARB");
	if( pfngl ) return (*pfngl)(programObj, name);
	return 0;
}

void glGetVertexAttribdvARB (GLuint index, GLenum pname, GLdouble *params)
{
	static PFNGLGETVERTEXATTRIBDVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETVERTEXATTRIBDVPROC) GLARB_GET_PROCADDRESS("glGetVertexAttribdvARB");
	if( pfngl ) (*pfngl)(index, pname, params);
}
void glGetVertexAttribfvARB (GLuint index, GLenum pname, GLfloat *params)
{
	static PFNGLGETVERTEXATTRIBFVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETVERTEXATTRIBFVPROC) GLARB_GET_PROCADDRESS("glGetVertexAttribfvARB");
	if( pfngl ) (*pfngl)(index, pname, params);
}
void glGetVertexAttribivARB (GLuint index, GLenum pname, GLint *params)
{
	static PFNGLGETVERTEXATTRIBIVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETVERTEXATTRIBIVPROC) GLARB_GET_PROCADDRESS("glGetVertexAttribivARB");
	if( pfngl ) (*pfngl)(index, pname, params);
}
void glGetVertexAttribPointervARB (GLuint index, GLenum pname, GLvoid* *pointer)
{
	static PFNGLGETVERTEXATTRIBPOINTERVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETVERTEXATTRIBPOINTERVPROC) GLARB_GET_PROCADDRESS("glGetVertexAttribPointervARB");
	if( pfngl ) (*pfngl)(index, pname, pointer);
}

void glVertexAttrib1dARB (GLuint index, GLdouble x)
{
	static PFNGLVERTEXATTRIB1DPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB1DPROC) GLARB_GET_PROCADDRESS("glVertexAttrib1dARB");
	if( pfngl ) (*pfngl)(index, x);
}
void glVertexAttrib1dvARB (GLuint index, const GLdouble *v)
{
	static PFNGLVERTEXATTRIB1DVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB1DVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib1dvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib1fARB (GLuint index, GLfloat x)
{
	static PFNGLVERTEXATTRIB1FPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB1FPROC) GLARB_GET_PROCADDRESS("glVertexAttrib1fARB");
	if( pfngl ) (*pfngl)(index, x);
}
void glVertexAttrib1fvARB (GLuint index, const GLfloat *v)
{
	static PFNGLVERTEXATTRIB1FVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB1FVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib1fvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib1sARB (GLuint index, GLshort x)
{
	static PFNGLVERTEXATTRIB1SPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB1SPROC) GLARB_GET_PROCADDRESS("glVertexAttrib1sARB");
	if( pfngl ) (*pfngl)(index, x);
}
void glVertexAttrib1svARB (GLuint index, const GLshort *v)
{
	static PFNGLVERTEXATTRIB1SVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB1SVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib1svARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib2dARB (GLuint index, GLdouble x, GLdouble y)
{
	static PFNGLVERTEXATTRIB2DPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB2DPROC) GLARB_GET_PROCADDRESS("glVertexAttrib2dARB");
	if( pfngl ) (*pfngl)(index, x, y);
}
void glVertexAttrib2dvARB (GLuint index, const GLdouble *v)
{
	static PFNGLVERTEXATTRIB2DVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB2DVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib2dvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib2fARB (GLuint index, GLfloat x, GLfloat y)
{
	static PFNGLVERTEXATTRIB2FPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB2FPROC) GLARB_GET_PROCADDRESS("glVertexAttrib2fARB");
	if( pfngl ) (*pfngl)(index, x, y);
}
void glVertexAttrib2fvARB (GLuint index, const GLfloat *v)
{
	static PFNGLVERTEXATTRIB2FVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB2FVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib2fvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib2sARB (GLuint index, GLshort x, GLshort y)
{
	static PFNGLVERTEXATTRIB2SPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB2SPROC) GLARB_GET_PROCADDRESS("glVertexAttrib2sARB");
	if( pfngl ) (*pfngl)(index, x, y);
}
void glVertexAttrib2svARB (GLuint index, const GLshort *v)
{
	static PFNGLVERTEXATTRIB2SVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB2SVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib2svARB");
	if( pfngl )(*pfngl)(index, v);
}
void glVertexAttrib3dARB (GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	static PFNGLVERTEXATTRIB3DPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB3DPROC) GLARB_GET_PROCADDRESS("glVertexAttrib3dARB");
	if( pfngl ) (*pfngl)(index, x, y, z);
}
void glVertexAttrib3dvARB (GLuint index, const GLdouble *v)
{
	static PFNGLVERTEXATTRIB3DVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB3DVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib3dvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib3fARB (GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	static PFNGLVERTEXATTRIB3FPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB3FPROC) GLARB_GET_PROCADDRESS("glVertexAttrib3fARB");
	if( pfngl ) (*pfngl)(index, x, y, z);
}
void glVertexAttrib3fvARB (GLuint index, const GLfloat *v)
{
	static PFNGLVERTEXATTRIB3FVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB3FVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib3fvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib3sARB (GLuint index, GLshort x, GLshort y, GLshort z)
{
	static PFNGLVERTEXATTRIB3SPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB3SPROC) GLARB_GET_PROCADDRESS("glVertexAttrib3sARB");
	if( pfngl ) (*pfngl)(index, x, y, z);
}
void glVertexAttrib3svARB (GLuint index, const GLshort *v)
{
	static PFNGLVERTEXATTRIB3SVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB3SVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib3svARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4NbvARB (GLuint index, const GLbyte *v)
{
	static PFNGLVERTEXATTRIB4NBVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4NBVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4NbvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4NivARB (GLuint index, const GLint *v)
{
	static PFNGLVERTEXATTRIB4NIVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4NIVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4NivARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4NsvARB (GLuint index, const GLshort *v)
{
	static PFNGLVERTEXATTRIB4NSVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4NSVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4NsvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4NubARB (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	static PFNGLVERTEXATTRIB4NUBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4NUBPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4NubARB");
	if( pfngl ) (*pfngl)(index, x, y, z, w);
}
void glVertexAttrib4NubvARB (GLuint index, const GLubyte *v)
{
	static PFNGLVERTEXATTRIB4NUBVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4NUBVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4NubvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4NuivARB (GLuint index, const GLuint *v)
{
	static PFNGLVERTEXATTRIB4NUIVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4NUIVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4NuivARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4NusvARB (GLuint index, const GLushort *v)
{
	static PFNGLVERTEXATTRIB4NUSVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4NUSVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4NusvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4bvARB (GLuint index, const GLbyte *v)
{
	static PFNGLVERTEXATTRIB4BVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4BVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4bvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4dARB (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	static PFNGLVERTEXATTRIB4DPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4DPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4dARB");
	if( pfngl ) (*pfngl)(index, x, y, z, w);
}
void glVertexAttrib4dvARB (GLuint index, const GLdouble *v)
{
	static PFNGLVERTEXATTRIB4DVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4DVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4dvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4fARB (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	static PFNGLVERTEXATTRIB4FPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4FPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4fARB");
	if( pfngl ) (*pfngl)(index, x, y, z, w);
}
void glVertexAttrib4fvARB (GLuint index, const GLfloat *v)
{
	static PFNGLVERTEXATTRIB4FVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4FVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4fvARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4ivARB (GLuint index, const GLint *v)
{
	static PFNGLVERTEXATTRIB4IVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4IVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4ivARB");
	if( pfngl ) (*pfngl)(index, v);
}
void glVertexAttrib4sARB (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	static PFNGLVERTEXATTRIB4SPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4SPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4sARB");
	if( pfngl ) (*pfngl)(index, x, y, z, w);
}
void glVertexAttrib4svARB (GLuint index, const GLshort *v)
{
	static PFNGLVERTEXATTRIB4SVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4SVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4svARB");
	if( pfngl ) (*pfngl)(index, v);

}
void glVertexAttrib4ubvARB (GLuint index, const GLubyte *v)
{
	static PFNGLVERTEXATTRIB4UBVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4UBVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4ubvARB");
	if( pfngl ) (*pfngl)(index, v);

}
void glVertexAttrib4uivARB (GLuint index, const GLuint *v)
{
	static PFNGLVERTEXATTRIB4UIVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4UIVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4uivARB");
	if( pfngl ) (*pfngl)(index, v);

}
void glVertexAttrib4usvARB (GLuint index, const GLushort *v)
{
	static PFNGLVERTEXATTRIB4USVPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIB4USVPROC) GLARB_GET_PROCADDRESS("glVertexAttrib4usvARB");
	if( pfngl ) (*pfngl)(index, v);

}
void glVertexAttribPointerARB (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
{
	static PFNGLVERTEXATTRIBPOINTERPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLVERTEXATTRIBPOINTERPROC) GLARB_GET_PROCADDRESS("glVertexAttribPointerARB");
	if( pfngl ) (*pfngl)(index, size, type, normalized, stride, pointer);
}

//#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_draw_buffers

void glDrawBuffersARB (GLsizei n, const GLenum *bufs)
{
	static PFNGLDRAWBUFFERSARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLDRAWBUFFERSARBPROC) GLARB_GET_PROCADDRESS("glDrawBuffersARB");
	if( pfngl ) (*pfngl)(n, bufs);
}

//#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_color_buffer_float

void glClampColorARB (GLenum target, GLenum clamp)
{
	static PFNGLCLAMPCOLORARBPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLCLAMPCOLORARBPROC) GLARB_GET_PROCADDRESS("glClampColorARB");
	if( pfngl ) (*pfngl)(target, clamp);
}

//#endif

/////////////////////////////////////////////////////////////////////
//
//
//
/////////////////////////////////////////////////////////////////////


//#ifdef GL_EXT_framebuffer_object

/////////////////////////////////////////////////////////////////////

GLboolean glIsRenderbufferEXT( GLuint renderbuffer )
{
	static PFNGLISRENDERBUFFEREXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLISRENDERBUFFEREXTPROC) GLARB_GET_PROCADDRESS("glIsRenderbufferEXT");
	return pfngl ? (*pfngl)( renderbuffer ) : 0;
}

void glBindRenderbufferEXT( GLenum target, GLuint renderbuffer )
{
	static PFNGLBINDRENDERBUFFEREXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLBINDRENDERBUFFEREXTPROC) GLARB_GET_PROCADDRESS("glBindRenderbufferEXT");
	if( pfngl ) (*pfngl)( target, renderbuffer );
}

void glDeleteRenderbuffersEXT( GLsizei n, const GLuint *renderbuffers )
{
	static PFNGLDELETERENDERBUFFERSEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLDELETERENDERBUFFERSEXTPROC) GLARB_GET_PROCADDRESS("glDeleteRenderbuffersEXT");
	if( pfngl ) (*pfngl)( n, renderbuffers );
}

void glGenRenderbuffersEXT( GLsizei n, GLuint *renderbuffers )
{
	static PFNGLGENRENDERBUFFERSEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGENRENDERBUFFERSEXTPROC) GLARB_GET_PROCADDRESS("glGenRenderbuffersEXT");
	if( pfngl ) (*pfngl)( n, renderbuffers );
}

void glRenderbufferStorageEXT( GLenum target, GLenum internalformat, GLsizei width, GLsizei height )
{
	static PFNGLRENDERBUFFERSTORAGEEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLRENDERBUFFERSTORAGEEXTPROC) GLARB_GET_PROCADDRESS("glRenderbufferStorageEXT");
	if( pfngl ) (*pfngl)( target, internalformat, width, height );
}

void glGetRenderbufferParameterivEXT( GLenum target, GLenum pname, GLint *params )
{
	static PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC) GLARB_GET_PROCADDRESS("glGetRenderbufferParameterivEXT");
	if( pfngl ) (*pfngl)( target, pname, params );
}

GLboolean glIsFramebufferEXT( GLuint framebuffer )
{
	static PFNGLISFRAMEBUFFEREXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLISFRAMEBUFFEREXTPROC) GLARB_GET_PROCADDRESS("glIsFramebufferEXT");
	return pfngl ? (*pfngl)( framebuffer ) : 0;
}

void glBindFramebufferEXT( GLenum target, GLuint framebuffer )
{
	static PFNGLBINDFRAMEBUFFEREXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLBINDFRAMEBUFFEREXTPROC) GLARB_GET_PROCADDRESS("glBindFramebufferEXT");
	if( pfngl ) (*pfngl)( target, framebuffer );
}

void glDeleteFramebuffersEXT( GLsizei n, const GLuint *framebuffers )
{
	static PFNGLDELETEFRAMEBUFFERSEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLDELETEFRAMEBUFFERSEXTPROC) GLARB_GET_PROCADDRESS("glDeleteFramebuffersEXT");
	if( pfngl ) (*pfngl)( n, framebuffers );
}

void glGenFramebuffersEXT( GLsizei n, GLuint *framebuffers )
{
	static PFNGLGENFRAMEBUFFERSEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGENFRAMEBUFFERSEXTPROC) GLARB_GET_PROCADDRESS("glGenFramebuffersEXT");
	if( pfngl ) (*pfngl)( n, framebuffers );
}

GLenum glCheckFramebufferStatusEXT( GLenum target )
{
	static PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC) GLARB_GET_PROCADDRESS("glCheckFramebufferStatusEXT");
	return pfngl ? (*pfngl)( target ) : (GLenum) 0;
}

void glFramebufferTexture1DEXT( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level )
{
	static PFNGLFRAMEBUFFERTEXTURE1DEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC) GLARB_GET_PROCADDRESS("glFramebufferTexture1DEXT");
	if( pfngl ) (*pfngl)( target, attachment, textarget, texture, level );
}

void glFramebufferTexture2DEXT( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level )
{
	static PFNGLFRAMEBUFFERTEXTURE2DEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC) GLARB_GET_PROCADDRESS("glFramebufferTexture2DEXT");
	if( pfngl ) (*pfngl)( target, attachment, textarget, texture, level );
}

void glFramebufferTexture3DEXT( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset )
{
	static PFNGLFRAMEBUFFERTEXTURE3DEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC) GLARB_GET_PROCADDRESS("glFramebufferTexture3DEXT");
	if( pfngl ) (*pfngl)( target, attachment, textarget, texture, level, zoffset );
}

void glFramebufferRenderbufferEXT( GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer )
{
	static PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC) GLARB_GET_PROCADDRESS("glFramebufferRenderbufferEXT");
	if( pfngl ) (*pfngl)( target, attachment, renderbuffertarget, renderbuffer );
}

void glGetFramebufferAttachmentParameterivEXT( GLenum target, GLenum attachment, GLenum pname, GLint *params )
{
	static PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) GLARB_GET_PROCADDRESS("glGetFramebufferAttachmentParameterivEXT");
	if( pfngl ) (*pfngl)( target, attachment, pname, params );
}

void glGenerateMipmapEXT( GLenum target )
{
	static PFNGLGENERATEMIPMAPEXTPROC pfngl = NULL;
	if( !pfngl ) pfngl = (PFNGLGENERATEMIPMAPEXTPROC) GLARB_GET_PROCADDRESS("glGenerateMipmapEXT");
	if( pfngl ) (*pfngl)( target );
}

//#endif

/////////////////////////////////////////////////////////////////////
