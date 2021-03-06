#version 150

out vec4 out_Color;

in vec2 pass_TexCoord;
in vec4 pass_PP_Mode;



const float pixelsize_x = 1.0 / 640;
const float pixelsize_y = 1.0 / 480;
const mat3  gaussiankernel      = mat3(1.0/16, 1.0/8, 1.0/16, 1.0/8, 1.0/4, 1.0/8, 1.0/16, 1.0/8,1.0/16);

uniform sampler2D ColorTex;

vec4 temp_color;
vec2 texcoord = pass_TexCoord;



void main(void)
{
	out_Color = texture(ColorTex, pass_TexCoord);
	//out_Color = vec4(1, 0, 0, 0);

	if(pass_PP_Mode.y == 1){
		texcoord.x =  1-texcoord.x;
		out_Color = texture(ColorTex, texcoord);
		//out_Color = vec4(1, 0, 1, 0);

			}
	if(pass_PP_Mode.z == 1){
		texcoord.y =  1-texcoord.y;
		out_Color = texture(ColorTex, texcoord);
		//out_Color = vec4(0, 1, 0, 0);

			}
	if(pass_PP_Mode.w == 1){
		vec4 sum = vec4(0);
		int i = 0;
		for(int x = -1; x<= 1; x++){
			int j = 0;
			for(int y = -1; y<= 1; y++){
				sum += texture(ColorTex, vec2(texcoord.x + x* pixelsize_x, texcoord.y + y* pixelsize_y))*gaussiankernel[i][j];
				++j;
			}
			++i;
		}
		out_Color= sum;
		//out_Color = vec4(1, 1, 1, 0);

	}
	if(pass_PP_Mode.x == 1){
		float luminance = out_Color.x * 0.2126 + out_Color.y * 0.7152 + out_Color.z * 0.0722;
		out_Color = vec4(luminance, luminance, luminance, 0);
		//out_Color = vec4(1, 1, 0, 0);

	}
}
