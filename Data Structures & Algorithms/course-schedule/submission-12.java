class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if (prerequisites.length == 0){
            return true;
        }

        // construct adj list
        var graph = graph(prerequisites);

        // dfs
        Set<Integer> visited = new HashSet<Integer>();
        Set<Integer> visiting = new HashSet<Integer>();
        for (int course: graph.keySet()){
            if (!visited.contains(course)){
                if (!dfs(course, graph, visited, visiting)){
                    return false;
                }
            }
        }
        return true;
    }

    public boolean dfs(int node, Map<Integer, Set<Integer>> graph, Set<Integer> visited, 
    Set<Integer> visiting){
        visited.add(node);
        visiting.add(node);

        for (var neighbor: graph.get(node)){
            // CYCLE 
            if (visiting.contains(neighbor)){
                return false;
            }

            if (!visited.contains(neighbor)){
                if (!dfs(neighbor, graph, visited, visiting)){
                    return false;
                }
            } 
        }

        visiting.remove(node);
        return true;
    }

    public Map<Integer, Set<Integer>> graph(int[][] edges){
        var graph = new HashMap<Integer, Set<Integer>>();
        for (int[] edge: edges){
            // directed
            var deps = graph.getOrDefault(edge[0], new HashSet<Integer>());
            deps.add(edge[1]);
            graph.put(edge[0], deps);
            
            deps = graph.getOrDefault(edge[1], new HashSet<Integer>());
            graph.put(edge[1], deps);
        }
        return graph;
    }
}
