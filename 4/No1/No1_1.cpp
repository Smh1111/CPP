#include<iostream>
#include<vector>
using namespace std;


void print_vec(const vector<double>& vec, ostream& out)
{
for (auto x: vec)
out << ' ' << x;
out << endl;
}

auto scale(vector<double> v1, double a) -> vector<double> {
  for (int i = 0; i <= v1.size() - 1; i++){
    v1[i] *= a;
  }
  return v1; 
}

auto add(vector<double> v1, vector<double> v2) -> vector<double>{
  
  if(v1.size() > v2.size()){
    for(int i=0;i<= v1.size() -2;i++){
        
      v1[i] +=  v2[i];
      return v1;
    }
    
  }
  else{
    for(int i=0;i<= v2.size() -2;i++){
        
      v2[i] +=  v1[i];
      return v2;
    }
  }
  
}


int main(){
  vector <double> vec1 = {2,1,4,3,7};
  vector <double> vec2 = {1,3,2,5};

    cout << "Hello";
 

  auto vec3 = scale(vec1, 1.5);
 
  print_vec(vec3, cout);
  cout << "jh";
  auto vec4 = add(vec3,vec2);
    print_vec(vec4, cout);
    
  auto vec5 = add(vec3, scale(vec2,-2.2));
print_vec(vec4, cout);
    
  return 0;
}