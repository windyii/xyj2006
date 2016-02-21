inherit ROOM;
#include <ansi.h>
#include <tomud.h>
#define TMI(x) ("\x19"+x+"\x1A")
int block_cmd(string);
void create ()
{
  set ("short", "�ϳǿ�ջ");
  set ("long", @LONG

��ҿ�ջ�������������ģ���������ǳ���¡����֮��Ǯ����������
��������ο���ŵ���ѡ��¶������߰������ӣ����̾����˵��ڴ�
�������������ﲻ�����������õ�С�������ػ��д����ķ����͡���
¥���������������ǿͷ���

LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sleep",
  "west" : __DIR__"zhuque-s1",
  "north" : __DIR__"giftroom",

  "up": "/d/wiz/entrance",
]));
   set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoer" : 1,
"/d/ourhome/npc/bigeye" : 1,
  "/lestat/bai" : 1,
"/d/city/npc/panguan":1,
"/d/ourhome/npc/seng" : 1,
]));
  set("no_time",1);

   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/nancheng_b", "???");

}

void init()
{
    add_action("block_cmd", "", 1);
    //write(TMI("bnway "));
    //write(TMI("lbclear0 "));
    //write(TMI("lbadd0 ǧ����(Qianli yan)01173;")+TMI("lbadd0 ������(Tang seng)01178;")+TMI("lbadd0 ��С��(Xiao er)01061;")+TMI("lbadd0 �����й�(Pan guan)01061;")+TMI("lbadd0 ������(Bai suzhen)01173;"));
   // write(TMI("bnway west;east;up;north;"));
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    return 0;
}

int valid_leave(object me, string dir)
{
        object mbox;

        if ( !me->query_temp("rent_paid") && dir == "east" )
        return notify_fail("��С��������Ц�ص�ס���㣺�Բ��𣬺����ǿ��˵��Է������Ǳ���Ŀ��ˣ�������š�\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "�㽫���佻�ظ��ʲ\n");
                destruct(mbox);
        }

        return ::valid_leave(me, dir);
}
