#You need to return the sum of new edges that can be made while preserving reachability. node u cannot reach a node v, if it couldn't reach that path previously

#Kosajaru to find strongly connected components, perform topological search, then for each node. 
#nodes are s, strongly connected components are c. components contains nodes.
#For every node, we get the number of nodes that are either in that component or is within a component that is topologically "later", and then subtract that value by one (because we don't want to consider the current node), subtract the value by the number of outgoing edges, and add this number to the final sum. 
#Final Sum is the answer