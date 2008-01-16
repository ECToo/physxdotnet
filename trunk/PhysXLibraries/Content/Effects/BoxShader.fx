float4x4 World;
float4x4 WorldViewProjection;
float3 lightPos1 = float3(1, 0, 0);
float4 lightColour;
float4 colour;
 
struct a2v
{
	float4 position		:POSITION0;
	float3 normal		:TEXCOORD1;
	float2 texCoord		:TEXCOORD0;
	float4 color		:COLOR;
};
 
struct v2p
{   	
	float4 position    : POSITION;
	float3 normal		: TEXCOORD1;
	float4 position3D	: TEXCOORD2;
	float2 texCoord		: TEXCOORD0;	
	float4 color		: COLOR;
};
 
struct p2f
{
    float4 color    : COLOR0;
};

float DotProduct(float3 lightPos, float3 pos, float3 normal)
{
     float3 lightDir = normalize(lightPos - pos);
     return dot(lightDir, normal);
};

void ps( in v2p IN,  out p2f OUT)
{	
	float dot = DotProduct(lightPos1, IN.position3D, IN.normal);
	
	OUT.color = (dot * colour) + (0.5 * colour); 
};

void vs( in a2v IN, out v2p OUT )
{      
	OUT.position = mul(IN.position, WorldViewProjection);
	OUT.normal = mul(IN.normal, World);
	OUT.texCoord = IN.texCoord;
	OUT.color = IN.color;
	OUT.position3D = mul(IN.position, World);	
};

technique Shader
{
    pass P0
    {      
        VertexShader = compile vs_2_0 vs();           
        PixelShader  = compile ps_2_0 ps();          
    }
}
