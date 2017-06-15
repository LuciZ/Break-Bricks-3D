#include "Item.h"

Item::Item()
{
	velocity = glm::vec3(0.0f, -1.0f, 0.0f);
	itemTTL = -1;
}

Item::~Item()
{
	applyItem(false);
}

void Item::initItem(Ball* ball, GameObject* player, const int itemType)
{
	this->ball = ball;
	this->player = player;
	this->itemType = itemType;
}

void Item::applyItem(bool apply)
{
	// ������ ����
	if (apply)
	{
		itemTTL = itemTime;
	}
	// �������ε� ����
	else if(itemTTL < 0)
	{
		return;
	}

	switch (itemType)
	{
	case POWER_UP:
	{
		if (apply)
		{
			ball->setPower(2);
			ball->setMaterial(GL2_Material::MAT_GOLD);
		}
		else
		{
			ball->setPower(1);
			ball->setMaterial(GL2_Material::MAT_RED);
		}
		break;
	}
	case SIZE_DOWN:
	{
		if (apply)
		{
			ball->setScale(glm::vec3(0.5f, 0.5f, 0.5f));
			ball->setMaterial(GL2_Material::MAT_BLUE);
		}
		else
		{
			ball->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
			ball->setMaterial(GL2_Material::MAT_RED);
		}
		break;
	}
	case SIZE_UP:
	{
		if (apply)
		{
			ball->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
			ball->setMaterial(GL2_Material::MAT_GREEN);
		}
		else
		{
			ball->setScale(glm::vec3(0.5f, 0.5f, 0.5f));
			ball->setMaterial(GL2_Material::MAT_RED);
		}
		break;
	}
	default:
		break;
	}
}

void Item::render()
{
	// ������ ��� ����
	if (itemTTL == -2)
	{
		return;
	}

	// ������ ���� �ȸԾ��� -> ȭ�鿡 ����
	if (itemTTL == -1)
	{
		// �������� ������ ��������.
		advanceOneTimeStep(0.02f);

		GameObject::render();
	}
	// ������ ��� ���� -> ������� ����
	else if (itemTTL == 0)
	{
		applyItem(false);
		itemTTL = -2;
	}
	// ������ ��� ��
	else
	{
		--itemTTL;
	}
}

bool Item::isItemAvailable()
{
	return itemTTL == -1;
}
