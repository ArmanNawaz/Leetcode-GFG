class Solution:
    def simplifyPath(self, path: str) -> str:
        curr, ans = "", ""
        st = []
        path += "/"
        
        for c in path: 
            if c == '/':
                if len(curr) == 0:
                    continue
                elif curr == "..":
                    if len(st) > 0:
                        st.pop()
                
                elif curr != ".":
                    st.append(curr)
                curr = ""
            
            else:
                curr += c
        
        
        while len(st) > 0:
            ans = "/" + st[-1] + ans
            st.pop()
        
        if len(ans) == 0: return "/"
        return ans