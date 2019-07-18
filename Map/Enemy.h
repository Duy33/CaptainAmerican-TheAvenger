﻿#pragma once
#include "Entity.h"
#include "Player.h"
#include "BoxCollider.h"
#include "Framework/Animation.h"
class Enemy: public Entity
{
public:
	virtual void Update(float dt) {}; // update animation và loại animation, gọi vũ khí
	virtual void Render() {}; // render loại animation tương ứng, gọi render của vũ khí
	virtual void OnCollision() {}; // xử lý va chạm của enemy và gọi xử lý va chạm vũ khí
	virtual void SetActive(bool IsActive) {}; // set enemy có đc render, update, oncollision hay không
	virtual void Delete() {}; // gọi khi enemy ra khỏi camera hoặc bị chết
	virtual void Spawn(); // sinh ra quái từ vị trí đc đọc từ file
	virtual void SetSpawnBox(float top, float left, float width, float height, Entity::Entity_Direction direction);
	Enemy();
	~Enemy();
protected:
	Animation* beaten_ani; 
	Animation* explode_ani;
	bool IsExplode;
	BoxCollider spawn_box; // box spawn cố định còn box va chạm khác
	
};
