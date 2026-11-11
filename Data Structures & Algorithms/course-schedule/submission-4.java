class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if (prerequisites.length == 0){
            return true;
        }

        // construct adj list
        var graph = graph(prerequisites);

        // dfs
        Set<Integer> visited = new HashSet<Integer>();
        for (int course: graph.keySet()){
            if (!dfs(course, graph, visited, new HashSet<Integer>())){
                return false;
            }

            if (visited.size() == numCourses){
                return true;
            }
        }
        return true;
    }

    public boolean dfs(int node, Map<Integer, Set<Integer>> graph, Set<Integer> visited, 
    Set<Integer> cur){
        visited.add(node);
        cur.add(node);

        for (var neighbor: graph.get(node)){
            if (!visited.contains(neighbor)){
                if (!dfs(neighbor, graph, visited, cur)){
                    return false;
                }
            } else if (cur.contains(neighbor)){
                return false;
            }
        }

        cur.remove(node);
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
