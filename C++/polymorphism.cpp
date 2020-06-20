

class LRUCache : Cache{
public:
	int capacity;
	LRUCache(int capacity) : capacity(capacity){
	}
	vector< pair<int,int> > seg;
	void set(int key,int value){
		for(int i = 0 ; i < seg.size() ; i++)
			if( seg[i].first == key ){
				seg[i].second = value;
				return;
			}
		if( seg.size() >= capacity ) seg.pop_back();
		seg.push_back({key,value});
	};
	int get(int key){
		int j = 0 ;
		for(int i = 0 ; i < seg.size() ; i++){
			if( seg[i].first == key ){
				for(int j = i - 1 ; j >= 0 ; j--){
					swap(seg[j],seg[j+1]);
				}
				return seg[0].second;
			}
		}
		return -1;
	}
};



