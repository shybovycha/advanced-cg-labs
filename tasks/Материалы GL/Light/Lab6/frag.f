varying	vec3 l;
varying	vec3 h;
varying vec3 v;
varying vec3 n;

uniform sampler2D samp;

void main (void)
{
	const vec4	diffColor = vec4 (0.61424, 0.04136, 0.04136, 0.45);
	const vec4	specColor = vec4 (0.727811, 0.626959, 0.626959, 0.55);
	const float	specPower = 51.2;
	vec3	n2   = normalize ( n );
	vec3	l2   = normalize ( l );
	vec3	h2   = normalize ( h );
	vec4	diff = diffColor * max ( dot ( n2, l2 ), 0.0 );
	vec4	spec = specColor * pow ( max ( dot ( n2, h2 ), 0.0 ), specPower );

	gl_FragColor = texture2D ( samp, gl_TexCoord [0].xy ) +diff + spec;
}
