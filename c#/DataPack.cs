using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EventManager
{
    //all data packet inherits from EventArgs
    class GameStart:EventArgs
    {
       public GameStart(string n,int a)
        {
            name = n;
            arg1 = a;
        }
       public string name;
       public int arg1;
    }
}
