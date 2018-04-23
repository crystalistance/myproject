//观察者模式

class Observer {
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update() {}
};

class Blog {
public:
    Blog() {}
    virtual ~Bolg() {}

    void Attach(Observer *observer) {
        m_Observers.push_back(observer);
    }

    void Detach(Observer *observer) {
        m_Observers.remove(observer);
    }

    void Notify() {
        list<Obserber*>::iterator it = m_Observers.begin();
        for (; it != it.end(); it++) {
            (*it)->Updata();   
        }
    }

    virtual void SetStatus(string s) {
        m_Status = s;
    }

    virtual string GetStatus() {
        return m_Status;
    }


protected:

};
