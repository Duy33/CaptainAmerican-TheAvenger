﻿#pragma once
#include "Entity.h"
#include "Player.h"
#include "Framework/Animation.h"
#include <math.h>
#include "SceneManager.h"
class Enemy: public Entity
{
public:
	virtual Animation* GetCurrentAnimation();
	virtual void Update(float dt); // update animation và loại animation, gọi vũ khí
	virtual int OnCollision(Entity*, float dt) override; // xử lý va chạm của enemy và gọi xử lý va chạm vũ khí
	virtual void SetActive(bool IsActive) {}; // set enemy có đc render, update, oncollision hay không
	virtual void Delete() {}; // gọi khi enemy ra khỏi camera hoặc bị chết
	virtual void Spawn(); // sinh ra quái từ vị trí đc đọc từ file
	virtual bool IsCollisionWithGround(float dt, int delta_y = 12);
	virtual void Draw() {};
	Enemy();
	virtual ~Enemy() override;
	// bool variable
	bool IsJumping;
protected:
	Animation* beaten_ani; 
	Animation* explode_ani;
	Animation* current_animation;
	bool IsExplode;
	D3DXVECTOR2 position_spawn;
	D3DXVECTOR2 position_goto;
	D3DXVECTOR2 position_loop;
};

