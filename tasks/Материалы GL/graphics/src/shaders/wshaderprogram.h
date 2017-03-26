#ifndef WSHADERPROGRAM_H
#define WSHADERPROGRAM_H

#include "wshader.h"


/////////////////////////////////////////////////////////////////////

class WShaderProgram
{
public:
	WShaderProgram();
	~WShaderProgram();

public:
	bool addShader( const WShader* shader );
	bool link();

	bool isLinked() const;
	bool isValid() const;

	void enable();
	void disable();

	std::string log() const;
	GLuint programId() const;

	void setValue1f( const char *name, float v1 );
	void getValue1f( const char *name, float &v1 );

	void setValue1i( const char *name, int v1 );
	void getValue1i( const char *name, int &v1 );

	void setValue3f( const char *name, float v1, float v2, float v3 );

private:
	GLint	progId;
};

/////////////////////////////////////////////////////////////////////

inline
void WShaderProgram::enable()
	{ glUseProgramObjectARB( programId() ); }

inline
void WShaderProgram::disable()
	{ glUseProgramObjectARB( 0 ); }

inline
GLuint WShaderProgram::programId() const
	{ return progId; }

/////////////////////////////////////////////////////////////////////
#endif // WSHADERPROGRAM_H
