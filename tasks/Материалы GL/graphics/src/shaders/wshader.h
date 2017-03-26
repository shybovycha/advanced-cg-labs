#ifndef WSHADERS_H
#define WSHADERS_H

#include <iostream>
#include <string>
#include "glextapi.h"

/////////////////////////////////////////////////////////////////////

class WShader
{
public:
	WShader( GLenum shType );
	~WShader();

public:
	bool compileSourceCode( const char* source );
	bool compileSourceFile( const char* fileName );

	bool isCompiled() const;
	std::string log() const;

	GLenum shaderType() const;
	GLuint shaderId() const;
	std::string sourceCode() const;

private:
	GLenum			shType;
	GLhandleARB		shId;
};

/////////////////////////////////////////////////////////////////////

inline 
GLenum WShader::shaderType() const
	{ return shType; }

inline 
GLuint WShader::shaderId() const
	{ return shId; }

/////////////////////////////////////////////////////////////////////
#endif // WSHADERS_H
