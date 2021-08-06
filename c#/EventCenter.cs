using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EventManager
{
    // singleton
    class Singleton<T> where T:class ,new()
    {
        private static T instance;
        public static T Instance
        {
            get { return instance; }
        }
        public static T GetIns()
        {
            if(instance==null)
            {
                var t = typeof(T);
                instance = new T();
            }
            return instance;
        }
        protected virtual void Awake()
        {
            //if (instance != null)
            //    Destroy(gameObject);
            //else
            //    instance = (T)this;
        }
        public static bool IsIniatialed
        {
            get { return instance != null; }
        }
        protected virtual void OnDestroy()
        {
            //if (instance == this)
            //    instance = null;
        }

    }
    
    // eventCenter, use interface from this class to add/remove listener and republish events.
    class EventCenter: Singleton<EventCenter>
    {
        public void AddListener(EventType t, Action<EventArgs> l)
        {
            if (listeners.TryGetValue(t, out Listener listener))
            {
                listener.AddOne(l);
            }
            else
            {
                listeners.Add(t, new Listener());
                listeners[t].AddOne(l);
            }

        }
        public void RemoveListener(EventType t, Action<EventArgs> l)
        {
            if (listeners.TryGetValue(t, out Listener listener))
            {
                listener.RemoveOne(l);
            }
        }
        public void RepublishEvent(EventType t,EventArgs arg)
        {
            if (listeners.TryGetValue(t, out Listener listener))
            {
                listener.Notify(arg);
            }
            else
            {
                listeners.Add(t, new Listener());
                listener.Notify(arg);
            }

        }

        Dictionary<EventType, Listener> listeners=new Dictionary<EventType, Listener>();
    }

  
}
