#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    if(!(cin>>N>>M)) return 0;
    vector<vector<double>> intimacy(N, vector<double>(N, 0.0));
    vector<int> gender(N, 0); // 0 unknown, 1 male, -1 female
    // we will parse photos as strings to keep -0
    for(int i=0;i<M;i++){
        int K; cin>>K;
        vector<int> ids(K);
        vector<int> isFemale(K);
        for(int j=0;j<K;j++){
            string s; cin>>s;
            bool neg = (!s.empty() && s[0]=='-');
            int absId;
            if(neg) absId = stoi(s.substr(1));
            else absId = stoi(s);
            ids[j]=absId;
            isFemale[j]=neg ? 1 : 0;
            // record gender
            if(absId>=0 && absId<N){
                gender[absId] = neg ? -1 : 1;
            }
        }
        double add = 1.0 / K;
        for(int a=0;a<K;a++){
            for(int b=a+1;b<K;b++){
                int u = ids[a], v = ids[b];
                if(u>=0 && u<N && v>=0 && v<N){
                    intimacy[u][v] += add;
                    intimacy[v][u] += add;
                }
            }
        }
    }
    string sA,sB;
    cin>>sA>>sB;
    // A and B are given as numbers with sign, need to parse as strings? Input line: "-3 2" etc numbers may be -0? Use string already read?
    // We read them as strings sA sB (already)
    bool negA = (!sA.empty() && sA[0]=='-');
    bool negB = (!sB.empty() && sB[0]=='-');
    int absA = negA ? stoi(sA.substr(1)) : stoi(sA);
    int absB = negB ? stoi(sB.substr(1)) : stoi(sB);
    int A = negA ? -absA : absA;
    int B = negB ? -absB : absB;
    // Ensure gender for A/B from sign (overrides)
    if(absA>=0 && absA<N) gender[absA] = negA ? -1 : 1;
    if(absB>=0 && absB<N) gender[absB] = negB ? -1 : 1;
    // fill unknown genders as male? For persons never appearing, assume male? But they will not be considered as opposite gender candidates if unknown. Better to leave unknown and skip.
    // For determining opposite sex, use gender array if known, otherwise infer: if gender==0, we cannot decide, skip. However we need to include all N persons: if never appeared, gender unknown, but they still have a gender. Problem guarantees each person has a gender. If they never appear in photos, gender remains unknown -> we cannot determine. But such persons have intimacy 0, won't be max unless all 0. To be safe, treat unknown as male except for 0? Instead we can default unknown to male for even? Not ideal. We'll treat unknown as male if id!=0? Actually for person 0, "-0" vs "0" distinction lost if we never saw photos, we can't know. We'll assume unknown male.
    for(int i=0;i<N;i++) if(gender[i]==0) gender[i]=1; // default male
    // But for 0 female case, if they appeared as -0 we already set -1.

    bool isA_male = !negA;
    bool isB_male = !negB;
    // For 0 special: neg flag tells female even if abs=0
    // isA_male already reflects.

    vector<int> bestA, bestB;
    double maxA = -1, maxB = -1;
    // Find max intimacy for opposite gender
    for(int i=0;i<N;i++){
        if(i==absA && false) continue; // include self? no
        // check gender opposite to A
        bool is_male = (gender[i]==1);
        if( (is_male && !isA_male) || (!is_male && isA_male) ){
            double v = intimacy[absA][i];
            if(v > maxA + 1e-9){
                maxA = v;
                bestA.clear();
                bestA.push_back(is_male ? i : -i);
                // handle -0: if i==0 and female, push 0? But -0 as int is 0, lose sign. Need to represent -0 as string "0"? Problem expects "-0" output? But int -0 prints 0. PTA expects "-0"??? Usually they expect "0" for female 0? Let's keep as -0 int 0 but output will be 0 not -0. For 0 female, should output "-0". We'll handle output separately.
                // Store signed value with special handling for 0 female.
                bestA.back() = (gender[i]==-1 && i==0) ? 0 : (is_male ? i : -i); // -0 becomes 0
                // We'll need to know if it's female zero to output "-0"
            }else if(fabs(v - maxA) < 1e-9){
                bestA.push_back(is_male ? i : -i);
            }
        }
        if( (is_male && !isB_male) || (!is_male && isB_male) ){
            double v = intimacy[absB][i];
            if(v > maxB + 1e-9){
                maxB = v;
                bestB.clear();
                bestB.push_back(is_male ? i : -i);
            }else if(fabs(v - maxB) < 1e-9){
                bestB.push_back(is_male ? i : -i);
            }
        }
    }
    // Need to keep track of female zero for output: we need to know gender[i]==-1 for i==0.
    // We'll generate output strings using helper
    auto signedToString = [&](int signedId, int genderOf)->string{
        // Actually signedId already encodes sign except for 0
        // For 0 we need to look at gender
        if(signedId==0){
            // need to know if it's female zero -> output "-0"
            // Determine by checking gender array for id 0
            // But signedId 0 could be male 0 or female 0; we need to differentiate.
            // We'll use gender of the target id (which we know)
            // However we lost info when pushing. Instead reconstruct: if gender[0]==-1 then it's female 0 => "-0"
            // But for bestA list we need per entry.
            // We'll just check: if the entry corresponds to id 0 and its intended gender is female -> "-0"
            // Since we pushed based on is_male, we can re-derive.
            // This helper will be called with signedId that may be 0, we need to know intended gender.
            // We'll instead generate string directly in output loop using stored gender info.
            return "0";
        }
        return to_string(signedId);
    };

    sort(bestA.begin(), bestA.end(), [](int a,int b){ return abs(a) < abs(b); });
    sort(bestB.begin(), bestB.end(), [](int a,int b){ return abs(a) < abs(b); });

    // check if mutually best
    bool aHasB = false, bHasA = false;
    for(int x: bestA) if(x==B) aHasB=true;
    // For -0 case, B may be 0 but sign lost; need to compare by abs and gender
    // Since B as int 0 loses sign, compare via string or via abs+gender
    // For 0 female, B == 0 (int) equals 0 male as well. To distinguish, compare abs and gender.
    // We'll do explicit check for 0.
    // Simpler: check by abs and gender equality
    auto isSamePerson = [&](int signedX, int targetAbs, bool targetIsMale)->bool{
        int absX = abs(signedX);
        if(absX != targetAbs) return false;
        // For abs 0, need to compare gender via sign of signedX
        if(absX==0){
            bool isMaleX = (signedX >=0); // 0 is considered male; but female -0 we stored as 0 so fails
            // For female zero we stored 0, so we can't distinguish. Use gender array? Not reliable.
            // Alternative: compare via target gender vs gender of signedX's id gender
            // For id 0, isMaleX should be derived from intended gender, not sign.
            // We have lost info. We'll instead directly check if intimacy max equals and consider they are pair if B's abs equals absA's counterpart?
            // Simpler: for 0 case, assume if target is female 0 and best list contains 0, consider it contains female 0.
            // We'll handle by checking abs only for 0.
            return true; // if abs same and 0, treat as same
        }
        bool isMaleX = (signedX > 0);
        return isMaleX == targetIsMale;
    };
    // Actually previous aHasB check using x==B fails for -0. We'll recompute using abs+gender
    aHasB = false; bHasA = false;
    for(int x: bestA){
        if(abs(x)==absB && ((x>0)==isB_male || (abs(x)==0)) ) { aHasB = true; break; }
        if(abs(x)==0 && absB==0) { aHasB = true; break; } // zero special
    }
    for(int x: bestB){
        if(abs(x)==absA && ((x>0)==isA_male || (abs(x)==0)) ) { bHasA = true; break; }
        if(abs(x)==0 && absA==0) { bHasA = true; break; }
    }

    bool mutuallyBest = aHasB && bHasA;
    // also need intimacy values equal to max (if there are ties, they are still mutually best if they are among best)
    // Spec: if A and B are exactly each other's most intimate, output only A B regardless of ties. So mutuallyBest suffices (they are among best). No need to check max equality separately beyond being in best lists.

    if(mutuallyBest){
        // output A B as original strings to preserve -0
        cout<<sA<<" "<<sB<<"\n";
    }else{
        // helper to output signed id correctly handling -0
        auto outputPair = [&](int baseAbs, bool baseIsMale, const vector<int>& bestList){
            // baseAbs not needed
            // For each best, construct string representation
            for(int signedId: bestList){
                int absId = abs(signedId);
                bool isMale = (signedId>0) || (signedId==0 && gender[absId]==1);
                // But for bestList, signedId may be 0 for female zero, we need to recover female
                // We pushed 0 for both male and female zero, lost info. Instead reconstruct from gender[absId] and whether this entry was intended to be opposite gender.
                // Actually bestList entries were pushed only for opposite gender, so for A male, best entries are female. So if absId==0, its gender is female (since opposite male). So we can infer: if absId==0, then isMale = false if bestList is for male base, true if base female.
                // Simpler: for absId==0, decide based on base gender opposite.
                string targetStr;
                if(absId==0){
                    // opposite gender to base
                    bool targetIsMale = ! (baseIsMale); // because best are opposite
                    targetStr = targetIsMale ? "0" : "-0";
                }else{
                    targetStr = (gender[absId]==1 ? to_string(absId) : to_string(-absId));
                    // gender array already defines sign, but for non-zero, signedId sign matches gender (since we pushed accordingly)
                    // Use signedId directly for non-zero
                    targetStr = to_string(signedId);
                }
                string baseStr = baseIsMale ? to_string(baseAbs) : (baseAbs==0 ? "-0" : to_string(-baseAbs));
                // But base string we have original sA/sB preserves -0 correctly, use original.
                // For base, use original string sA or sB
            }
        };
        // Instead of complex, directly output using sA and appropriate target string
        // We'll generate target strings properly.
        for(int signedId: bestA){
            int absId = abs(signedId);
            string target;
            if(absId==0){
                // opposite to A
                target = isA_male ? "-0" : "0";
            }else{
                // signedId already correct for non-zero; but for female zero case handled above
                target = to_string(signedId);
            }
            cout<<sA<<" "<<target<<"\n";
        }
        for(int signedId: bestB){
            int absId = abs(signedId);
            string target;
            if(absId==0){
                target = isB_male ? "-0" : "0";
            }else{
                target = to_string(signedId);
            }
            cout<<sB<<" "<<target<<"\n";
        }
    }
    return 0;
}
