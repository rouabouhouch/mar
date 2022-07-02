#pragma once

class Mario
{

	float x;
	float y;

	
public:
	Mario();
	sf::FloatRect get_hit_box() const;
};
