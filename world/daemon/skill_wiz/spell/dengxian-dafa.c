// dengxian-dafa.c �����ɴ󷨡�
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("dengxian-dafa", 1) )
                return
notify_fail("��ķ�����Ϊ����������޷�ѧϰ���ɴ󷨡�\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/xueshan/dengxian-dafa/" + spell;
}

string type() { return "magic"; }