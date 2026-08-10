void compress(vector<int> &v){//pass the vector u want to compress
  sort(all(v);
  v.erase(unique(all(v)),v.end());
}

int idx(int val,vector<int> &compressedVector)//pass the value u want to know it's compressed value, and the compressed vector.
{
  return lower_bound(all(compressedVector),val)-compressedVector.begin();
}
