#include "Money.h"
#include "MCUtil.h"

Money::Money()
{

}

Money::~Money()
{

}

void Money::createSprite(Vec2 pos, Money_Type mtype)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	m_MoneySprite = Sprite::create(getMoneyImg(mtype));
	m_MoneySprite->setScale(0.6); //
	m_MoneySprite->setPosition(Vec2(pos.x - m_MoneySprite->getContentSize().width*0.3, pos.y));
	this->addChild(m_MoneySprite, 1);
}

const char* Money::getMoneyImg(Money_Type mtype)
{
/*
	const char* imgName;
	switch (mtype)
	{
	case Real_100_T:
		imgName = "money/total_100.jpg";
		break;
	case Fake_100_T:
		imgName = "money/total_fake_100.jpg";
		break;
	case Real_100_S:
		imgName = "money/single_100.jpg";
		break;
	case Fake_100_S:
		imgName = "money/single_fake_100.jpg";
		break;
	default:
		imgName = "money/total_100.jpg";
		break;
	}
	return imgName;*/

	return MCUtil::filename[mtype].c_str();

}

void Money::changeMoney(Money_Type mtype)
{
	m_MoneySprite->setTexture(getMoneyImg(mtype));
}

void Money::moneyFly(float detax, float detay, float detat)
{
	MoveTo *MoveD = MoveTo::create(detat, ccp(m_MoneySprite->getPositionX() + detax, m_MoneySprite->getPositionY() + detay));
	ScaleTo *Scale = ScaleTo::create(detat, 0.4, 0.4);
	Sequence *Seq = Sequence::create(Scale, MoveD, NULL);          //上述各个语句定义组成一个动作序列，让各动作依次运行。
	Repeat *repeateAct = Repeat::create(Seq, 1);

	m_MoneySprite->runAction(repeateAct);
}

void Money::moneyMove(float x, float y, float detat)
{
	MoveTo *MoveD = MoveTo::create(detat, ccp(m_MoneySprite->getPositionX() + x, m_MoneySprite->getPositionY() + y));
	MoveTo *MoveU = MoveTo::create(detat, ccp(m_MoneySprite->getPositionX(), m_MoneySprite->getPositionY()));
	Sequence *Seq = Sequence::create(MoveD, MoveU, NULL);
	Repeat *repeateAct = Repeat::create(Seq, 1);

	m_MoneySprite->runAction(repeateAct);
}

void Money::setPos(float detax, float detay)
{
	m_MoneySprite->setPosition(m_MoneySprite->getPositionX() + detax, m_MoneySprite->getPositionY() + detay);
}



