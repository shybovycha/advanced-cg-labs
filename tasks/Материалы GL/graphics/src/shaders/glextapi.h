/*
 * glarb.h
 * 
 * 
 *
 */

#ifndef __GLARB_H__
#define __GLARB_H__

// OpenGL headers
////#ifdef WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/glext.h"
////#endif
//#if defined (__APPLE__) || defined (OSX)
//#include <OpenGL/gl.h>
//#include <OpenGL/glu.h>
//#include <OpenGL/glext.h>
//#else
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glext.h>
////#endif

/////////////////////////////////////////////////////////////////////

////#ifdef GL_ARB_multitexture

void glActiveTextureARB (GLenum texture);
void glClientActiveTextureARB (GLenum texture);
void glMultiTexCoord1dARB (GLenum target, GLdouble s);
void glMultiTexCoord1dvARB (GLenum target, const GLdouble *v);
void glMultiTexCoord1fARB (GLenum target, GLfloat s);
void glMultiTexCoord1fvARB (GLenum target, const GLfloat *v);
void glMultiTexCoord1iARB (GLenum target, GLint s);
void glMultiTexCoord1ivARB (GLenum target, const GLint *v);
void glMultiTexCoord1sARB (GLenum target, GLshort s);
void glMultiTexCoord1svARB (GLenum target, const GLshort *v);
void glMultiTexCoord2dARB (GLenum target, GLdouble s, GLdouble t);
void glMultiTexCoord2dvARB (GLenum target, const GLdouble *v);
void glMultiTexCoord2fARB (GLenum target, GLfloat s, GLfloat t);
void glMultiTexCoord2fvARB (GLenum target, const GLfloat *v);
void glMultiTexCoord2iARB (GLenum target, GLint s, GLint t);
void glMultiTexCoord2ivARB (GLenum target, const GLint *v);
void glMultiTexCoord2sARB (GLenum target, GLshort s, GLshort t);
void glMultiTexCoord2svARB (GLenum target, const GLshort *v);
void glMultiTexCoord3dARB (GLenum target, GLdouble s, GLdouble t, GLdouble r);
void glMultiTexCoord3dvARB (GLenum target, const GLdouble *v);
void glMultiTexCoord3fARB (GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord3fvARB (GLenum target, const GLfloat *v);
void glMultiTexCoord3iARB (GLenum target, GLint s, GLint t, GLint r);
void glMultiTexCoord3ivARB (GLenum target, const GLint *v);
void glMultiTexCoord3sARB (GLenum target, GLshort s, GLshort t, GLshort r);
void glMultiTexCoord3svARB (GLenum target, const GLshort *v);
void glMultiTexCoord4dARB (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glMultiTexCoord4dvARB (GLenum target, const GLdouble *v);
void glMultiTexCoord4fARB (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4fvARB (GLenum target, const GLfloat *v);
void glMultiTexCoord4iARB (GLenum target, GLint s, GLint t, GLint r, GLint q);
void glMultiTexCoord4ivARB (GLenum target, const GLint *v);
void glMultiTexCoord4sARB (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void glMultiTexCoord4svARB (GLenum target, const GLshort *v);

////#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_vertex_buffer_object

void glBindBufferARB (GLenum target, GLuint buffer);
void glDeleteBuffersARB (GLsizei n, const GLuint *buffers);
void glGenBuffersARB (GLsizei n, GLuint *buffers);
GLboolean glIsBufferARB (GLuint buffer);
void glBufferDataARB (GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
void glBufferSubDataARB (GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
void glGetBufferSubDataARB (GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
GLvoid* glMapBufferARB (GLenum target, GLenum access);
GLboolean glUnmapBufferARB (GLenum target);
void glGetBufferParameterivARB (GLenum target, GLenum pname, GLint *params);
void glGetBufferPointervARB (GLenum target, GLenum pname, GLvoid* *params);

//#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_shader_objects

void glDeleteObjectARB(GLhandleARB obj);
GLhandleARB glGetHandleARB(GLenum pname);
void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
GLhandleARB glCreateShaderObjectARB(GLenum shaderType);
void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB* *string, const GLint *length);
void glCompileShaderARB(GLhandleARB shaderObj);
GLhandleARB glCreateProgramObjectARB(void);
void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj);
void glLinkProgramARB(GLhandleARB programObj);
void glUseProgramObjectARB(GLhandleARB programObj);
void glValidateProgramARB(GLhandleARB programObj);
void glUniform1fARB(GLint location, GLfloat v0);
void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform1iARB(GLint location, GLint v0);
void glUniform2iARB(GLint location, GLint v0, GLint v1);
void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform1fvARB(GLint location, GLsizei count, const GLfloat *value);
void glUniform2fvARB(GLint location, GLsizei count, const GLfloat *value);
void glUniform3fvARB(GLint location, GLsizei count, const GLfloat *value);
void glUniform4fvARB(GLint location, GLsizei count, const GLfloat *value);
void glUniform1ivARB(GLint location, GLsizei count, const GLint *value);
void glUniform2ivARB(GLint location, GLsizei count, const GLint *value);
void glUniform3ivARB(GLint location, GLsizei count, const GLint *value);
void glUniform4ivARB(GLint location, GLsizei count, const GLint *value);
void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat *params);
void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint *params);
void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
GLint glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB *name);
void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat *params);
void glGetUniformivARB(GLhandleARB obj, GLint location, GLint *params);
void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);

//#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_vertex_shader

void glDisableVertexAttribArrayARB(GLuint index);
void glEnableVertexAttribArrayARB(GLuint index);
void glBindAttribLocationARB (GLhandleARB programObj, GLuint index, const GLcharARB *name);
void glGetActiveAttribARB (GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
GLint glGetAttribLocationARB (GLhandleARB programObj, const GLcharARB *name);

void glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
void glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
void glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
void glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid* *pointer);

void glVertexAttrib1d (GLuint index, GLdouble x);
void glVertexAttrib1dv (GLuint index, const GLdouble *v);
void glVertexAttrib1f (GLuint index, GLfloat x);
void glVertexAttrib1fv (GLuint index, const GLfloat *v);
void glVertexAttrib1s (GLuint index, GLshort x);
void glVertexAttrib1sv (GLuint index, const GLshort *v);
void glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dv (GLuint index, const GLdouble *v);
void glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fv (GLuint index, const GLfloat *v);
void glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
void glVertexAttrib2sv (GLuint index, const GLshort *v);
void glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dv (GLuint index, const GLdouble *v);
void glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fv (GLuint index, const GLfloat *v);
void glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3sv (GLuint index, const GLshort *v);
void glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
void glVertexAttrib4Niv (GLuint index, const GLint *v);
void glVertexAttrib4Nsv (GLuint index, const GLshort *v);
void glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
void glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
void glVertexAttrib4Nusv (GLuint index, const GLushort *v);
void glVertexAttrib4bv (GLuint index, const GLbyte *v);
void glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dv (GLuint index, const GLdouble *v);
void glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fv (GLuint index, const GLfloat *v);
void glVertexAttrib4iv (GLuint index, const GLint *v);
void glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4sv (GLuint index, const GLshort *v);
void glVertexAttrib4ubv (GLuint index, const GLubyte *v);
void glVertexAttrib4uiv (GLuint index, const GLuint *v);
void glVertexAttrib4usv (GLuint index, const GLushort *v);
void glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);

//#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_draw_buffers

void glDrawBuffersARB (GLsizei n, const GLenum *bufs);

//#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_ARB_color_buffer_float

void glClampColorARB (GLenum target, GLenum clamp);

//#endif

/////////////////////////////////////////////////////////////////////

//#ifdef GL_EXT_framebuffer_object

GLboolean glIsRenderbufferEXT( GLuint renderbuffer );
void glBindRenderbufferEXT( GLenum target, GLuint renderbuffer );
void glDeleteRenderbuffersEXT( GLsizei n, const GLuint *renderbuffers );
void glGenRenderbuffersEXT( GLsizei n, GLuint *renderbuffers );
void glRenderbufferStorageEXT( GLenum target, GLenum internalformat, GLsizei width, GLsizei height );
void glGetRenderbufferParameterivEXT( GLenum target, GLenum pname, GLint *params );
GLboolean glIsFramebufferEXT( GLuint framebuffer );
void glBindFramebufferEXT( GLenum target, GLuint framebuffer );
void glDeleteFramebuffersEXT( GLsizei n, const GLuint *framebuffers );
void glGenFramebuffersEXT( GLsizei n, GLuint *framebuffers );
GLenum glCheckFramebufferStatusEXT( GLenum target );
void glFramebufferTexture1DEXT( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level );
void glFramebufferTexture2DEXT( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level );
void glFramebufferTexture3DEXT( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset );
void glFramebufferRenderbufferEXT( GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer );
void glGetFramebufferAttachmentParameterivEXT( GLenum target, GLenum attachment, GLenum pname, GLint *params );
void glGenerateMipmapEXT( GLenum target );

//#endif

/////////////////////////////////////////////////////////////////////
#endif // __GLARB_H__
