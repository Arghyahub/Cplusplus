class SnapshotArray {
    map<int,map<int,int> > mp;
    int snp = 0;
public:
    SnapshotArray(int length) {
        for (int i=0; i<length; i++){
            mp[i][0] = 0;
        }
    }
    
    void set(int index, int val) {
        mp[index][snp] = val ;
    }
    
    int snap() {
        return snp++;
    }
    
    int get(int index, int snap_id) {
        auto it = mp[index].upper_bound(snap_id) ; it--;
        return it->second;
    }
};
