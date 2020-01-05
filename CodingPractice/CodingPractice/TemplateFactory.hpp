// Template Factory Method
template <class Base>
class Factory
{
public:
    virtual unique_ptr<Base> getObject() = 0;
    virtual ~Factory(){}
};
template <class Base, class Derived>
class MyFactory:public Factory<Base>
{
public:
    unique_ptr<Base> getObject()
    {
        unique_ptr<Base> b(new Derived);
        return b;
    }
};

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

template<class T>
void someFrameworkCode(Factory<T>* ab)
{
    unique_ptr<T> p = ab->getObject();
    p->execute();
}
