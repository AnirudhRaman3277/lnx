#include <vector> 
#include <algorithm> 
using namespace std; 
 
int main() { 
    vector<int> frames; 
    int capacity = 3; 
    int ref[] = {5, 0, 2, 3, 0, 1, 3, 4, 5, 4, 2, 0, 3, 4, 3}; 
    int n = sizeof(ref) / sizeof(ref[0]); 
    int page_faults = 0, page_hits = 0; 
 
    for (int i = 0; i < n; i++) { 
        int page = ref[i]; 
        auto it = find(frames.begin(), frames.end(), page); 
 
        if (it == frames.end()) { 
            // Page Fault 
            page_faults++; 
            if (frames.size() == capacity) 
                frames.erase(frames.begin()); // Remove LRU 
        } else { 
            // Page Hit 
            page_hits++; 
            frames.erase(it); // Move to most recent 
        } 
 
        frames.push_back(page); // Add current page to MRU 
        // Optional: Display current frame content 
        cout << "Frame: "; 
        for (int f : frames) cout << f << " "; 
        cout << endl; 
    } 
 
    cout << "\nTotal Page Faults: " << page_faults << endl; 
    cout << "Total Page Hits: " << page_hits << endl; 
 
    return 0; 
} 
