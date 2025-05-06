#include "Fossils.h"
#include "Inventory.h"



Fossils::Fossils(int x, int y)
{
	//Нераскопанные 
	TextureLand.loadFromFile("Land.png");
	LandSprite.setTexture(TextureLand);
	LandSprite.setTextureRect(sf::IntRect(0, 0, 270, 203));
	LandSprite.setPosition(x, y);

	TextureTools.loadFromFile("Tools.png");

	//Кирка
	PickaxeSprite.setTexture(TextureTools);
	PickaxeSprite.setTextureRect(sf::IntRect(0, 0, 88, 75));
	PickaxeSprite.setPosition
	(
		LandSprite.getPosition().x + (LandSprite.getGlobalBounds().width - PickaxeSprite.getGlobalBounds().width) / 2,
		LandSprite.getPosition().y + (LandSprite.getGlobalBounds().height - PickaxeSprite.getGlobalBounds().height) / 2
	);
	isVisiblePickaxe = false;

	//Лопата
	ShovelSprite.setTexture(TextureTools);
	ShovelSprite.setTextureRect(sf::IntRect(0, 75, 88, 75));
	ShovelSprite.setPosition
	(
		LandSprite.getPosition().x + (LandSprite.getGlobalBounds().width - ShovelSprite.getGlobalBounds().width) / 2,
		LandSprite.getPosition().y + (LandSprite.getGlobalBounds().height - ShovelSprite.getGlobalBounds().height) / 2
	);

	//Кисть 
	BrushSprite.setTexture(TextureTools);
	BrushSprite.setTextureRect(sf::IntRect(0, 150, 88, 75));
	BrushSprite.setPosition
	(
		LandSprite.getPosition().x + (LandSprite.getGlobalBounds().width - BrushSprite.getGlobalBounds().width) / 2,
		LandSprite.getPosition().y + (LandSprite.getGlobalBounds().height - BrushSprite.getGlobalBounds().height) / 2
	);


	isVisibleShovel = false;
	Trigger = false;
};
void Fossils::ToolsControl(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (!Trigger) return;

		if (isToolDelayActive && toolDelayTimer.getElapsedTime().asSeconds() < 1.0f) //Задержка для использования инструментов
		{
			return;
		}
		if (ev.key.code == sf::Keyboard::E)
		{
			PlayerHand = Pickaxe;
			Excavation();
			isToolDelayActive = true;
			toolDelayTimer.restart();
		}
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::R)
		{
			PlayerHand = Shovel;
			Excavation();
			isToolDelayActive = true;
			toolDelayTimer.restart();
		}
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::T)
		{
			PlayerHand = Brush;
			Excavation();
			isToolDelayActive = true;
			toolDelayTimer.restart();
		}
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Y)
		{
			PlayerHand = None;
			Excavation();

		}
		
	}
	
}
void Fossils::UpdateTrigger(const sf::Sprite& playerSprite)
{
	Trigger = LandSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds());
}
void Fossils::Update(float time)
{
	//Анимации инструментов
	if (AnimPickaxe)
	{
		if (!DirectPickaxe)
		{
			// Прямая анимация
			FramePickaxe += time * speedTools; 
			if (FramePickaxe >= 4) 
			{
				FramePickaxe = 2;
				DirectPickaxe = true; 
			}
		}
		else
		{
			// Обратная анимация
			FramePickaxe -= time * speedTools;
			if (FramePickaxe <= 0)
			{
				FramePickaxe = 0;
				DirectPickaxe = false;
				currentAnimationCycle++;

				if (currentAnimationCycle >= 4)
				{
					AnimPickaxe = false;
					isVisiblePickaxe = false;
				}
			}
		}

		PickaxeSprite.setTextureRect(sf::IntRect(88 * static_cast<int>(FramePickaxe), 0, 88, 75));
	}
	if (AnimShovel)
	{
		if (!DirectShovel)
		{
			// Прямая анимация
			FrameShovel += time * speedTools;
			if (FrameShovel >= 4)
			{
				FrameShovel = 2;
				DirectShovel = true;
			}
		}
		else
		{
			// Обратная анимация
			FrameShovel -= time * speedTools;
			if (FrameShovel <= 0)
			{
				FrameShovel = 0;
				DirectShovel = false;
				currentAnimationCycle++;

				if (currentAnimationCycle >= 4)
				{
					AnimShovel = false;
					isVisibleShovel = false;
				}
			}
		}

		ShovelSprite.setTextureRect(sf::IntRect(88 * static_cast<int>(FrameShovel), 75, 88, 75));
	}
	if (AnimBrush)
	{
		if (!DirectBrush)
		{
			// Прямая анимация
			FrameBrush += time * speedTools;
			if (FrameBrush >= 4)
			{
				FrameBrush = 2;
				DirectBrush = true;
			}
		}
		else
		{
			// Обратная анимация
			FrameBrush -= time * speedTools;
			if (FrameBrush <= 0)
			{
				FrameBrush = 0;
				DirectBrush = false;
				currentAnimationCycle++;

				if (currentAnimationCycle >= 4)
				{
					AnimBrush = false;
					isVisibleBrush = false;
				}
			}
		}

		BrushSprite.setTextureRect(sf::IntRect(88 * static_cast<int>(FrameBrush),150, 88, 75));
	}


	//Смена спрайта состоянии раскопки
	if (shouldChangeLandPickaxe && landChangeTimer.getElapsedTime().asSeconds() >= 1.0f && ImmersionLevel == 3)
	{
		DrawLandLevel3();
		shouldChangeLandPickaxe = false;
	}
	else if (shouldChangeLandShovel && landChangeTimer.getElapsedTime().asSeconds() >= 1.0f && ImmersionLevel == 2) 
	{
		DrawLandLevel2();
		shouldChangeLandShovel = false;
	}
	else if (shouldChangeLandBrush && landChangeTimer.getElapsedTime().asSeconds() >= 1.0f && ImmersionLevel == 1)
	{
		DrawLandLevel1();
		shouldChangeLandBrush = false;
	}	
	else if (shouldChangeLandHand && landChangeTimer.getElapsedTime().asSeconds() >= 1.0f && ImmersionLevel == 0)
	{
		DrawLandLevel0(true);
		shouldChangeLandHand = false;
	}

}	

void Fossils::draw(sf::RenderWindow& window)
{
	window.draw(LandSprite);
	if (isVisiblePickaxe)
	{
		window.draw(PickaxeSprite);
	}
	if (isVisibleShovel) {
		window.draw(ShovelSprite);
	}
	if (isVisibleBrush) 
	{
		window.draw(BrushSprite);
	}
};