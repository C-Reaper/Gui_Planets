#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/TransformedView.h"

#include "/home/codeleaded/System/Static/Library/Random.h"

// Compression also with pngs


TransformedView tv;
unsigned int colors[] = {
	GRAY,
	LIGHT_GRAY,
	WHITE,
	DARK_RED,
	RED,
	LIGHT_RED,
	DARK_GREEN,
	GREEN,
	LIGHT_GREEN,
	DARK_BLUE,
	BLUE,
	LIGHT_BLUE,
	DARK_YELLOW,
	YELLOW,
	LIGHT_YELLOW,
	DARK_CYAN,
	CYAN,
	LIGHT_CYAN,
	DARK_MAGENTA,
	MAGENTA,
	LIGHT_MAGENTA,
	DARK_ORANGE,
	ORANGE,
	LIGHT_ORANGE,
	DARK_VIOLETTE,
	VIOLETTE,
	LIGHT_VIOLETTE,
	DARK_ROSE,
	ROSE,
	LIGHT_ROSE,
	DARK_BROWN,
	BROWN,
	LIGHT_BROWN,
	GOLD,
	SILBER
};

void Setup(AlxWindow* w){
	tv = TransformedView_Make(
		(Vec2){ GetWidth(),GetHeight() },
		(Vec2){ 0.0f,0.0f },
		(Vec2){ 0.01f,0.01f },
		(float)GetWidth() / (float)GetHeight()
	);
}
void Update(AlxWindow* w){
	TransformedView_HandlePanZoom(&tv,w->Strokes,GetMouse());
	const Vec2 origin = TransformedView_ScreenWorldPos(&tv,(Vec2){ 0.0f,0.0f });

	Clear(BLACK);

	const Vec2 br = TransformedView_ScreenWorldPos(&tv,(Vec2){ GetWidth(),GetHeight() });

	double avg_dt = 0.0;

	for(int i = (int)origin.y;i<=(int)br.y;i++){
		for(int j = (int)origin.x;j<=(int)br.x;j++){
			const long long v = (unsigned long long)i << 32U | (unsigned long long)j;
			
			Timepoint tp0 = Time_Nano();

			Random_Set(v);
			const unsigned int out = Random_u32_MinMax(0,0xFFFF);

			Timepoint tp1 = Time_Nano();
			const FDuration dt = Time_Elapsed(tp0,tp1);
			avg_dt = (avg_dt + dt) * 0.5f;

			if(out < 16U){
				const float rad = Random_f64_MinMax(1.0f,10.0f);
				const unsigned int col = Random_u32_MinMax(0,sizeof(colors) / sizeof(*colors));
				
				const Vec2 pos = TransformedView_WorldScreenPos(&tv,(Vec2){ j,i });
				const Vec2 len = TransformedView_WorldScreenLength(&tv,(Vec2){ rad,rad });
				Circle_R_Render(WINDOW_STD_ARGS,pos,len,colors[col]);
			}
		}
	}

	CStr_RenderAlxFontf(WINDOW_STD_ARGS,GetAlxFont(),0.0f,0.0f,RED,"DT: %f",avg_dt);
}
void Delete(AlxWindow* w){
	
}

int main(){
    if(Create("Planets (Procedural Generated)",1900,1200,1,1,Setup,Update,Delete))
        Start();
    return 0;
}