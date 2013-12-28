uniform sampler2DRect incoming_tex;

void main(void)
{
//	vec4 texel = texelFetch( incoming_tex, ivec2(fftIndex), 0 );  // Выборка без фильтрации

//	vec3 color0 = texture2DRect( incoming_tex, gl_TexCoord[0].st ).rgb;
//	float gv = dot( color0, vec3( 0.2125, 0.7154, 0.0721 ) );
//	gl_FragColor = vec4( vec3( gv ), gl_Color.a );
	gl_FragColor = vec4( 1, 0, 0, 1 );
}