using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EventManager
{
    // a class contains one action
    class Listener
    {
        public void AddOne(Action<EventArgs> a)
        {
            NotifyAll += a;
        }
        public void RemoveOne(Action<EventArgs> a)
        {
            NotifyAll -= a;
        }

        public void Notify(EventArgs a)
        {
            NotifyAll(a);
        }
        Action<EventArgs> NotifyAll = (EventArgs arg) => { };
    }
}
