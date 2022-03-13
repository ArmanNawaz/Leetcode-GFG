class Solution:
    def isValid(self, s: str) -> bool:
        
        st = []
        
        for c in s:
            if(c == '(' or c == '{' or c == '['):
                st.append(c)
            elif(len(st) > 0 and st[-1] == '(' and c == ')'): st.pop()
            elif(len(st) > 0 and st[-1] == '{' and c == '}'): st.pop()
            elif(len(st) > 0 and st[-1] == '[' and c == ']'): st.pop()
            else: return False
        
        if len(st) > 0: 
            return False
        return True
