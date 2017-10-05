#include "BattleMenu.h"
#include "Save.h"

BattleMenu::BattleMenu()
{
    setStrings({ "�Ƅ�", "��W", "�ö�", "�ⶾ", "�t��", "��Ʒ", "�ȴ�", "��B", "�Ԅ�", "�Y��" });
}

BattleMenu::~BattleMenu()
{
}

void BattleMenu::onEntrance()
{
    for (auto c : childs_)
    {
        c->setVisible(true);
    }

    //�ƶ����򲻿��ƶ�
    if (role->Moved)
    {
        childs_[0]->setVisible(false);
    }
    if (role->getLearnedMagicCount() <= 0)
    {
        childs_[1]->setVisible(false);
    }
    //�ö�
    if (role->UsePoison <= 0)
    {
        childs_[2]->setVisible(false);
    }
    //�ⶾ
    if (role->Detoxification <= 0)
    {
        childs_[3]->setVisible(false);
    }
    //ҽ��
    if (role->Medcine <= 0)
    {
        childs_[4]->setVisible(false);
    }
    //���õȴ�
    childs_[6]->setVisible(false);
    arrange(0, 0, 0, 28);
}

int BattleMenu::runAsRole(Role* r)
{
    setRole(r);
    return run();
}

