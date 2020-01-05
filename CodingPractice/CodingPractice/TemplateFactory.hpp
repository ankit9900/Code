// Template Factory Method

// A templated factory class
template <class Base>
class Factory
{
public:
    virtual Base* getObject() = 0;
    virtual ~Factory(){}
};
template <class Base, class Derived>
class MyFactory:public Factory<Base>
{
public:
    Base* getObject()
    {
        return new Derived();
    }
};
---------------------------------------------------------
class Task
{
public:
  virtual void execute() = 0;
  virtual ~Task(){}
};

class EMailTask : public Task
{
public:
    void execute()
        {
                std::cout<<"Executing EMailTask "<<std::endl;
        }
};
class SMSTask : public Task
{
public:
        void execute()
        {
                std::cout<<"Executing SMSTask "<<std::endl;
        }
};
class VoiceTask : public Task
{
public:
        void execute()
        {
                std::cout<<"Executing VoiceTask "<<std::endl;
        }
};
----------------------------
// Templated function which uses above class    
template<class T>
void someFrameworkCode(Factory<T>* ab)
{
    T* p = ab->getObject();
    p->execute();
    delete p;
}

------------------

// USAGE

Factory<Task>* t = new MyFactory<Task, EMailTask>();
    
    someFrameworkCode(t);

    Factory<Task>* t2 = new MyFactory<Task, VoiceTask>();
    
    someFrameworkCode(t2);
