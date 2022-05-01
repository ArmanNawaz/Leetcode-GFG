class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        # Daily
        st = deque()
        
        for ch in s:
            if ch == '#':
                if len(st) > 0:
                    st.pop()
            else:
                st.append(ch)
                
        st2 = deque()
        
        for ch in t:
            if ch == '#':
                if len(st2) > 0:
                    st2.pop()
            else:
                st2.append(ch)
        
        
        return st == st2