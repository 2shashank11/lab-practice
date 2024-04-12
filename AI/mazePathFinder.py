class graph:
    def __init__(self):
        self.visited=[]
        self.stk=[]
        self.path=[]
    
    def dfs(self, g, start, end):
        self.stk.append(start)
        item=[]

        while(len(self.stk)!=0):
            u=self.stk[-1]

            if(u==end):
                self.path.append(u)
                return

            if(u not in self.visited):
                self.visited.append(u)
                self.path.append(u)
                item=g[u]

                for i in g[u]:
                    if(i not in self.visited):
                        self.stk.append(i)
            
            else:
                self.path.pop(-1)
                self.stk.pop(-1)
            
            for ele in item :
                if ele not in self.visited:
                        self.stk.append(ele)
                else :
                    item.remove(ele)

g=graph()
g.list={ 2:[1,3] ,3:[2,8], 8:[3,7], 1:[2,6], 6:[1,11], 11:[6,12], 12:[11,17] , 17:[16,18],16:[17],18:[17,19] , 19:[14,18], 14:[9,13,19],9:[14,10], 10:[5,9,15], 15:[10,20] , 20:[15] ,5:[10,4], 4:[5], 7:[8], 13: [14] }
g.dfs(g.list, 2, 20)
print(g.path)
