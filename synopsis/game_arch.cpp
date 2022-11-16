#include <iostream>
#include <list>

enum Types
{
	SHOOT, DEATH
};

struct Msg
{
	int type;
};

struct Sprite{};

class Manager
{
private:
	std::list<GameObject*> objects;
	std::list<Msg*> msgs;
public:
	void Update(int dt)
	{
		for (auto x : objects)
		{
			x->Update(dt);
		}
		for (auto msg : msgs)
		{
			switch (msg->type)
			{
			case SHOOT:
				break;
			case DEATH:
				break;
			}
			for (auto x : objects)
			{
				x->SendMsg(*msg);
			}
		}
	}
	void SendMsg(Msg msg);
	void Draw();
};

class GameObject
{
protected:
	int pos[2], r;
	Sprite texture;
public:
	virtual void SendMsg(Msg msg) = 0;
	virtual void Update(int dt) = 0;
	virtual void Draw() = 0;
};

class StaticObject : public GameObject
{

};

class DynamicObject : public GameObject
{
protected:
	float speed, dir[2];
};

class Unit : public DynamicObject
{
protected:
	int hp, max_hp;
};

class MeleeU : public Unit
{

};

class Swordsman : public MeleeU
{

};

class RangeU : public Unit
{
protected:
	int atk_range;
};

class Archer : public RangeU
{

};

class Catapult : public RangeU
{

};

class Item : public DynamicObject
{

};
