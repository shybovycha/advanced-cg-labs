/*
 *
 *
 *
 *
 *
 */

#include "wshader.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>


/////////////////////////////////////////////////////////////////////

WShader::WShader( GLenum shType )
{
	this->shType = shType;
	this->shId = glCreateShaderObjectARB( shType );
}

WShader::~WShader()
{
	if( shId )
	{
		glDeleteObjectARB( shId );
		shId = 0;
	}
}

/////////////////////////////////////////////////////////////////////

bool WShader::compileSourceCode( const char* source )
{
	if( !shaderId() ) return false;
	GLint len = strlen( source );
    glShaderSourceARB( shaderId(), 1, (const char**) &source, &len );
	glCompileShaderARB( shaderId() );
    return glGetError() == GL_NO_ERROR;
}

bool WShader::compileSourceFile( const char* fileName )
{
	int fh = _open( fileName, _O_RDONLY | _O_TEXT ); // C4996
	if( fh == -1 )
	{
		printf( "Open failed on input file %s", fileName );
		return false;
	}

	size_t len = _filelength( fh );
	char* buf = new char [ len + 1 ];
	int rd = _read( fh, buf, len );
	buf[ rd ] = 0;
	_close( fh );

    bool result = compileSourceCode( buf );
	delete [] buf;

	return result;
}

/////////////////////////////////////////////////////////////////////

bool WShader::isCompiled() const
{
	GLint compileStatus;
    glGetObjectParameterivARB( shaderId(), GL_OBJECT_COMPILE_STATUS_ARB, &compileStatus );
    return compileStatus != 0;
}

/////////////////////////////////////////////////////////////////////

std::string WShader::log() const
{
	GLcharARB infoLog[1024] = "";
	glGetInfoLogARB( shaderId(), sizeof(infoLog), NULL, infoLog );
	return std::string( infoLog );
}

/////////////////////////////////////////////////////////////////////
