template<class infoType>
class AbsQueue
{
public:
	virtual bool Empty() const =0;
	virtual void EnQueue( const infoType &x)=0;
	virtual void DeQueue()=0;
	//virtual infoType GetHead() const =0;
	virtual ~AbsQueue(){}
};