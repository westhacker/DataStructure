class AbsList
{
public:
	virtual void Clear()=0;
	virtual int Length() const =0;
	virtual bool IsEmpty() const =0;
	virtual bool IsFull() const =0;
	virtual bool Insert(int i,const char &x)=0;
	virtual bool Delete(int i)=0;
	virtual int Find(const char &x) =0;
	virtual bool Get(int i,char &x) const=0;
	virtual void Output() const=0;
	virtual ~AbsList(){};
};