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
	trigger_ = false;
};
void Fossils::ToolsControl(sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed) {
		if (!trigger_) return;

		//Задержка для использования инструментов
		if (isToolDelayActive && toolDelayTimer.getElapsedTime().asSeconds() < 1.0f)  {
			return;
		}
		if (ev.key.code == sf::Keyboard::E) {
			PlayerHand = Pickaxe;
			Excavation();
			isToolDelayActive = true;
			toolDelayTimer.restart();
		}
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::R) {
			PlayerHand = Shovel;
			Excavation();
			isToolDelayActive = true;
			toolDelayTimer.restart();
		}
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::T) {
			PlayerHand = Brush;
			Excavation();
			isToolDelayActive = true;
			toolDelayTimer.restart();
		}
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Y) {
			PlayerHand = None;
			Excavation();

		}
		
	}
	
}
void Fossils::UpdateTrigger(const sf::Sprite& playerSprite)
{
	trigger_ = LandSprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds());
}
void Fossils::Update(float time)
{
	//Анимации инструментов
	if (animPickaxe_) {
		if (!directPickaxe_) {
			// Прямая анимация
			framePickaxe_ += time * speedTools; 
			if (framePickaxe_ >= 4) 
			{
				framePickaxe_ = 2;
				directPickaxe_ = true; 
			}
		}
		else
		{
			// Обратная анимация
			framePickaxe_ -= time * speedTools;
			if (framePickaxe_ <= 0) {
				framePickaxe_ = 0;
				directPickaxe_ = false;
				currentAnimationCycle_++;

				if (currentAnimationCycle_ >= 4) {
					animPickaxe_ = false;
					isVisiblePickaxe = false;
				}
			}
		}

		PickaxeSprite.setTextureRect(sf::IntRect(88 * static_cast<int>(framePickaxe_), 0, 88, 75));
	}
	if (animShovel_)
	{
		if (!directShovel_) {
			// Прямая анимация
			frameShovel_ += time * speedTools;
			if (frameShovel_ >= 4) {
				frameShovel_ = 2;
				directShovel_ = true;
			}
		}
		else {
			// Обратная анимация
			frameShovel_ -= time * speedTools;
			if (frameShovel_ <= 0) {
				frameShovel_ = 0;
				directShovel_ = false;
				currentAnimationCycle_++;

				if (currentAnimationCycle_ >= 4) {
					animShovel_ = false;
					isVisibleShovel = false;
				}
			}
		}
		ShovelSprite.setTextureRect(sf::IntRect(88 * static_cast<int>(frameShovel_), 75, 88, 75));
	}
	if (animBrush_) {
		if (!directBrush_) {
			// Прямая анимация
			frameBrush_ += time * speedTools;
			if (frameBrush_ >= 4) {
				frameBrush_ = 2;
				directBrush_ = true;
			}
		}
		else {
			// Обратная анимация
			frameBrush_ -= time * speedTools;
			if (frameBrush_ <= 0) {
				frameBrush_ = 0;
				directBrush_ = false;
				currentAnimationCycle_++;

				if (currentAnimationCycle_ >= 4) {
					animBrush_ = false;
					isVisibleBrush = false;
				}
			}
		}

		BrushSprite.setTextureRect(sf::IntRect(88 * static_cast<int>(frameBrush_),150, 88, 75));
	}


	//Смена спрайта состоянии раскопки
	if (shouldChangeLandPickaxe_ && landChangeTimer.getElapsedTime().asSeconds() >= 1.0f && immersionLevel_ == 3) {
		DrawLandLevel3();
		shouldChangeLandPickaxe_ = false;
	}
	else if (shouldChangeLandShovel_ && landChangeTimer.getElapsedTime().asSeconds() >= 1.0f && immersionLevel_ == 2)  {
		DrawLandLevel2();
		shouldChangeLandShovel_ = false;
	}
	else if (shouldChangeLandBrush_ && landChangeTimer.getElapsedTime().asSeconds() >= 1.0f && immersionLevel_ == 1) {
		DrawLandLevel1();
		shouldChangeLandBrush_ = false;
	}	
	else if (shouldChangeLandHand_ && landChangeTimer.getElapsedTime().asSeconds() >= 1.0f && immersionLevel_ == 0) {
		DrawLandLevel0(true);
		shouldChangeLandHand_ = false;
	}

}	

void Fossils::Excavation()
{
	if (LevelSatiety > 0) {
		if (immersionLevel_ == 4) {
			if (PlayerHand == Pickaxe) UsingPickaxe(true);
			else if (PlayerHand == Shovel && EnduranceShovel > 0) UsingShovel(false);
			else if (PlayerHand == Brush && EnduranceBrush > 0) UsingBrush(false);

		}
		else if (immersionLevel_ == 3) {
			if (PlayerHand == Pickaxe && EndurancePickaxe > 0) UsingPickaxe(false);
			else if (PlayerHand == Shovel && EnduranceShovel > 0) UsingShovel(true);
			else if (PlayerHand == Brush && EnduranceBrush > 0) UsingPickaxe(false);
		}
		else if (immersionLevel_ == 2) {
			if (PlayerHand == Pickaxe) UsingPickaxe(false);
			else if (PlayerHand == Shovel) UsingShovel(false);
			if (PlayerHand == Brush) UsingBrush(true);
		}
		//Подбор раскопки
		else if (immersionLevel_ == 1) {
			if (PlayerHand == Pickaxe) UsingPickaxe(false);
			else if (PlayerHand == Shovel) UsingShovel(false);
			if (PlayerHand == None) {
				AddFossil();
				DrawLandLevel0(true);
				immersionLevel_ = 0;
			}
			
		}
		LevelSatiety--;
		DeadPlayer();
	}
	else {
		DeadPlayer();
	}
};
void Fossils::UsingPickaxe(bool RightTool)
{
	if (RightTool == true && EndurancePickaxe > 0) {
		isVisiblePickaxe = true;
		animPickaxe_ = true;
		framePickaxe_ = 0;
		directPickaxe_ = false;
		currentAnimationCycle_ = 0;

		landChangeTimer.restart();
		shouldChangeLandPickaxe_ = true;
		DamagePickaxe(15);
		immersionLevel_ = 3;
	}
	else if (RightTool == false && EndurancePickaxe > 0) {
		if (immersionLevel_ == 3) {
			isVisiblePickaxe = true;
			animPickaxe_ = true;
			framePickaxe_ = 0;
			directPickaxe_ = false;
			currentAnimationCycle_ = 0;

			DamagePickaxe(25);
			DrawLandLevel4();
		}
		else if (immersionLevel_ < 3) {
			isVisiblePickaxe = true;
			animPickaxe_ = true;
			framePickaxe_ = 0;
			directPickaxe_ = false;
			currentAnimationCycle_ = 0;

			DamagePickaxe(25);
			DrawLandLevel0(false);
		}
	}
	Hand PlayerHand = None;
}
void Fossils::UsingShovel(bool RightTool)
{
	if (RightTool == true && EnduranceShovel > 0) {
		isVisibleShovel = true;
		animShovel_ = true;
		frameShovel_ = 0;
		directShovel_ = false;
		currentAnimationCycle_ = 0;

		landChangeTimer.restart();
		shouldChangeLandShovel_ = true;
		DamageShovel(20);
		immersionLevel_ = 2;
	}
	else if (RightTool == false && EnduranceShovel > 0) {
		if (immersionLevel_ < 3) {
			isVisibleShovel = true;
			animShovel_ = true;
			frameShovel_ = 0;
			directShovel_ = false;
			currentAnimationCycle_ = 0;

			DamageShovel(30);
			DrawLandLevel0(false);
		}
	}
}
void Fossils::UsingBrush(bool RightTool)
{
	if (RightTool == true && EnduranceBrush > 0) {
		isVisibleBrush = true;
		animBrush_ = true;
		frameBrush_ = 0;
		directBrush_ = false;
		currentAnimationCycle_ = 0;

		landChangeTimer.restart();
		shouldChangeLandBrush_ = true;
		DamageBrush(30);
		immersionLevel_ = 1;
	}
	else if (RightTool == false && EnduranceBrush != 0) {
		isVisibleBrush = true;
		animBrush_ = true;
		frameBrush_ = 0;
		directBrush_ = false;
		currentAnimationCycle_ = 0;

		DamageBrush(50);
	}
}
void Fossils::TakeBones()
{
	shouldChangeLandHand_ = true;
	immersionLevel_ = 0;
}

void Fossils::draw(sf::RenderWindow& window)
{
	window.draw(LandSprite);
	if (isVisiblePickaxe) {
		window.draw(PickaxeSprite);
	}
	if (isVisibleShovel) {
		window.draw(ShovelSprite);
	}
	if (isVisibleBrush) {
		window.draw(BrushSprite);
	}
};