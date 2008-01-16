float4x4 World;
float4x4 WorldViewProjection;
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

void ps( in v2p IN,  out p2f OUT)
{		
	OUT.color = colour; 
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
