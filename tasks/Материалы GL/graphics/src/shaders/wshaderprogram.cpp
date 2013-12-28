#include "wshaderprogram.h"
#include <GL\glu.h>


/////////////////////////////////////////////////////////////////////

WShaderProgram::WShaderProgram()
{
	progId = glCreateProgramObjectARB();
}

WShaderProgram::~WShaderProgram()
{

}

/////////////////////////////////////////////////////////////////////

bool WShaderProgram::addShader( const WShader* shader )
{
	if( !programId() || !shader || !shader->shaderId() ) return false;
	glAttachObjectARB( programId(), shader->shaderId() );
	return true;
}

/////////////////////////////////////////////////////////////////////

bool WShaderProgram::link()
{
	if( !programId() ) return false;
	glLinkProgramARB( programId() );
	return isLinked();
}

/////////////////////////////////////////////////////////////////////

bool WShaderProgram::isLinked() const
{
	GLint linkStatus;
    glGetObjectParameterivARB( programId(), GL_OBJECT_LINK_STATUS_ARB, &linkStatus );
    return linkStatus != 0;
}

bool WShaderProgram::isValid() const
{
    GLint validated;
	glValidateProgramARB( programId() );
    glGetObjectParameterivARB( programId(), GL_OBJECT_VALIDATE_STATUS_ARB, &validated );
	return validated != 0;
}

/////////////////////////////////////////////////////////////////////

std::string WShaderProgram::log() const
{
	GLcharARB infoLog[1024] = "";
	glGetInfoLogARB( programId(), sizeof(infoLog), NULL, infoLog );
	return std::string( infoLog );
}

/////////////////////////////////////////////////////////////////////

void WShaderProgram::setValue1f( const char *name, float v1 )
{
	GLint loc = glGetUniformLocationARB( programId(), name );
	glUniform1fARB( loc, v1 );
	GLenum err = glGetError();
	const GLubyte *msg = gluErrorString( err );
}

void WShaderProgram::getValue1f( const char *name, float &v1 )
{
	GLint loc = glGetUniformLocationARB( programId(), name );
	glGetUniformfvARB( programId(), loc, &v1 );
}

void WShaderProgram::setValue1i( const char *name, int v1 )
{
	GLint loc = glGetUniformLocationARB( programId(), name );
	glUniform1iARB( loc, v1 );
	GLenum err = glGetError();
	const GLubyte *msg = gluErrorString( err );
}

void WShaderProgram::getValue1i( const char *name, int &v1 )
{
	GLint loc = glGetUniformLocationARB( programId(), name );
	glGetUniformivARB( programId(), loc, &v1 );
}

void WShaderProgram::setValue3f( const char *name, float v1,float v2, float v3 )
{
	GLint loc = glGetUniformLocationARB( programId(), name );
	glUniform3fARB( loc, v1, v2, v3 );
}

/////////////////////////////////////////////////////////////////////