#pragma once
#include "Product.h"
#include "iostream"

class ShopList :
	public Product
{
public:
	ShopList();
	~ShopList();
	void GenerateShopList(int Itens[]);
};

