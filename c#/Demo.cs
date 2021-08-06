using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EventManager
{
    //a demo class shows how to use eventsystem
    public class Demo
    {
        public void f()
        {
            EventCenter.GetIns().AddListener(EventType.GAME_START, OnXXX);
        }
        void OnXXX(EventArgs arg)
        {
            GameStart data = arg as GameStart;
            Console.WriteLine(data.name);
        }
    }
}
