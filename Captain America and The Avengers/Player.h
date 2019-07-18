#pragma once
#include "Entity.h"
#include "PlayerState.h"
#include <map>
#include "Collision.h"

// Player
#define PLAYER_SIZE_WIDTH 8
#define PLAYER_SIZE_HEIGHT 40
#define PLAYER_FOOT_HEIGHT 8
//
#define VELOCITY_X 80.0f
#define VELOCITY_Y 160.0f
// jumping
#define DELTA_JUMP 0.3f
#define DISTANCE_JUMPING 90.0f
#define TIME_AIR 0.4f
#define TIME_JUMPING 0.2f
#define TIME_ROLLING 0.3f
#define TIME_KICKING 0.16
// Dashing
#define TIME_DASHING 0.016 * 36
#define TIME_DUCK_BEFORE_DASHING  0.016* 1
#define TIME_WAIT_DASHING 0.016f * 0
// Throwing
#define TIME_THROWING 0.016 * 14
#define TIME_WAIT_THROWING 0.016f * 4
// Punching
#define TIME_PUNCHING 0.016 * 13
#define TIME_WAIT_PUNCHING 0.016f * 4
// Ducking - Punching
#define TIME_DUCKING_PUNCHING 0.016f*8
#define TIME_WAITING_DUCKING_PUNCHING 0.016*3



using namespace std;
class Player : public Entity
{
public:
	
	static Player* GetInstance();
	Player();
	~Player();
	void Update(float dt);
	void Render();
	void Draw();
	void HandleInput(float dt);
	void Init();
	void ChangeState(PlayerState* new_state);
	PlayerState::NameState GetCurrentState();
	PlayerState* GetPlayerState();
	void SetCurrentState(PlayerState::NameState new_state);
	void SetCurrentAnimation(Animation* animation);

	Animation* GetCurrentAnimation();
	Animation* GetAnimation(PlayerState::NameState state);

	void SetPosition(float x, float y) override;
	void AddTimeBuffer(float dt);
	float GetTimeBuffer();
	void SetTimeBuffer(float dt);
	void SetIsRolling(bool IsRolling);
	bool GetIsRolling();
	void SetIsThrowing(bool IsThrowing);
	bool GetIsThrowing();
	void SetPositionIdle(D3DXVECTOR2 position_idle);
	D3DXVECTOR2 GetPositionIdle();
	Entity::Entity_Direction previous_direction;
	void SetIsDuckingPunching(bool IsDuckingpunching);
	bool GetIsDuckingPunching();

	bool IsCollisionWithGround(float dt, int delta_y = 12);
protected:
	static Player *instance;
	std::map<int, Animation*> animations;
	PlayerState::NameState current_state;
	PlayerState* player_state;
	Animation* animation;
	D3DXVECTOR2 position_idle;
	float time_buffer;
	bool IsRolling;
	bool IsThrowing;
	bool IsDuckingPunching;
};
