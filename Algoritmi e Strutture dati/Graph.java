import java.util.*;
import java.lang.*;
import java.io.*;
import 
// A class to represent a connected, directed and weighted graph
public class Graph {
	// A class to represent a weighted edge in graph
	class Edge {
		int src, dest, weight;
		Edge()
		{
			src = dest = weight = 0;
		}
	};

	int V, E;
	Edge edge[];

	// Creates a graph with V vertices and E edges
	Graph(int v, int e)
	{
		V = v;
		E = e;
		edge = new Edge[e];
		for (int i = 0; i < e; ++i)
			edge[i] = new Edge();
	}
/*
	void Dijkstra(Graph graph, int src)
	{
		int V = graph.V, E = graph.E;
		int dist[] = new int[V];
		int s[] = new int [V];
		int n = 1;

		for(int i = 0; i < V; i++) {
			if(graph.edge[i].src == src)
				dist[graph.edge[i].dest] = graph.edge[i].weight;
			else 
				dist[graph.edge[i].dest] = Integer.MAX_VALUE;
		}
		s[src] = 1;
		dist[src] = 0

		
		while (n < V) {
			for(int i = 0; i < V; i++) {
				int tmp = Integer.MAX_VALUE;
				if (dist[i] < tmp && s[i] == 0) {
					int tmp = dist[i];
					int w = i;
				}
				s[w] = 1;
				n++;
				for(int i = 0; i<V; i++)
					if(s[i]==0) dist[i] = Integer.min(dist[i], dist[w]+)

			}
		}

	}
*/
	// The main function that finds shortest distances from src
	// to all other vertices using Bellman-Ford algorithm. 
	void BellmanFord(Graph graph, int src)
	{
		int V = graph.V, E = graph.E;
		int dist[] = new int[V];

		// Step 1: Initialize distances from src to all other vertices as INFINITE
		for (int i = 0; i < V; ++i)
			dist[i] = Integer.MAX_VALUE;
		dist[src] = 0;

		// Step 2: Relax all edges |V| - 1 times. A simple
		// shortest path from src to any other vertex can
		// have at-most |V| - 1 edges
		for (int i = 1; i < V; ++i) {
			for (int j = 0; j < E; ++j) {
				int u = graph.edge[j].src;
				int v = graph.edge[j].dest;
				int weight = graph.edge[j].weight;
				if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v])
					dist[v] = dist[u] + weight;
			}
		}

		// Step 3: check for negative-weight cycles. The above
        // step guarantees shortest distances if graph doesn't
        // contain negative weight cycle. If we get a shorter
        // path, then there is a cycle.
        for (int j = 0; j < E; ++j) {
            int u = graph.edge[j].src;
            int v = graph.edge[j].dest;
            int weight = graph.edge[j].weight;
            if (dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]) {
                System.out.println("Graph contains negative weight cycle");
                return;
            }

		printArr(dist, V);
	}

	// A utility function used to print the solution
	void printArr(int dist[], int V)
	{
		System.out.println("\nVertex | Distance from Source");
		for (int i = 0; i < V; ++i)
			System.out.println("   " + i + "\t\t  " + dist[i]);
	}

	public static void main(String[] args)
	{
		int V = 5; // Number of vertices in graph
		int E = 7; // Number of edges in graph

		Graph graph = new Graph(V, E);
		
		graph.edge[0].src = 0;
		graph.edge[0].dest = 1;
		graph.edge[0].weight = 2;

		graph.edge[1].src = 0;
		graph.edge[1].dest = 4;
		graph.edge[1].weight = 10;

		graph.edge[2].src = 1;
		graph.edge[2].dest = 2;
		graph.edge[2].weight = 3;

		graph.edge[3].src = 1;
		graph.edge[3].dest = 4;
		graph.edge[3].weight = 7;

		graph.edge[4].src = 2;
		graph.edge[4].dest = 3;
		graph.edge[4].weight = 4;

		graph.edge[5].src = 2;
		graph.edge[5].dest = 4;
		graph.edge[5].weight = 6;

		graph.edge[6].src = 3;
		graph.edge[6].dest = 4;
		graph.edge[6].weight = 5;

		graph.BellmanFord(graph, 0);
	}
}