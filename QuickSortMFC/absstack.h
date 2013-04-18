template <class infoType>
class AbsStack{
public:
	AbsStack(){}
	virtual ~AbsStack(){}
	virtual bool empty()const=0;
	virtual bool full() const=0;
    virtual void clear()=0;
	virtual void push(const infoType &x)=0;
	virtual infoType pop()=0;
	virtual infoType getTop() const=0;
};