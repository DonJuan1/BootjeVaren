#pragma once


class Cannon
{
public:
	Cannon();
	virtual ~Cannon() {};

	virtual int getDamage() = 0;

protected:

};