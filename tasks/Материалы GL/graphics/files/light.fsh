
varying vec3 N;
varying vec3 L;

//uniform vec3 eyePos; // Eye Position

uniform sampler2D myTexture;

void main (void)
{
	vec4 ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
	//globalAmbient = gl_LightModel.ambient * gl_FrontMaterial.ambient;

	vec3 eyePos = vec3( 0, 0, 1);
	vec3 E = normalize(eyePos);// - v);
	vec3 R = normalize(2.0 * dot(N,L) * N-L); // R = normalize(-reflect(L,N));

	float spec = pow(max(dot(R,E),0.0), gl_FrontMaterial.shininess);

	float diffuse = max(dot(N,L),0.0);
	diffuse = smoothstep(diffuse, 0.0, 0.5);

	vec4 texval1 = texture2D(myTexture, vec2(gl_TexCoord[0]));

	gl_FragColor = texval1;
//	gl_FragColor = ambient + gl_FrontMaterial.diffuse * diffuse + gl_FrontMaterial.specular * spec;
}