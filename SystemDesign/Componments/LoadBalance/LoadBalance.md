# Load Balancing

## Overview

Load Balancer typically sits between client and server.
1. Helps to spread the traffic across a cluster of servers to improve **responsiveness** and **availability**.
2. Keeps track of the status of all the resources while distributing requests.  

By balancing application requests across multiple servers, a load balancer reduces individual server load and prevents any one application server from becoming a single point of failure, thus improving overall application availability and responsiveness.

![Load Balancer General](../../assets/LoadBalancerGeneral.png)

To utilize full scalability and redundancy, we can try to balance the load at each layer of the system. We can add LBs at three places:

* Between the user and the web server
* Between web servers and an internal platform layer, like application servers or cache servers
* Between internal platform layer and database.

![Load Balancer Application](../../assets/LoadBalancerApplication.png)

## Benefits
1. Users experience faster, uninterrupted service. Users won’t have to wait for a single struggling server to finish its previous tasks. Instead, their requests are immediately passed on to a more readily available resource.
2. Service providers experience less downtime and higher throughput. Even a full server failure won’t affect the end user experience as the load balancer will simply route around it to a healthy server.
3. Load balancing makes it easier for system administrators to handle incoming requests while decreasing wait time for users.
4. Smart load balancers provide benefits like predictive analytics that determine traffic bottlenecks before they happen. As a result, the smart load balancer gives an organization actionable insights. These are key to automation and can help drive business decisions.
5. System administrators experience fewer failed or stressed components. Instead of a single device performing a lot of work, load balancing has several devices perform a little bit of work.

## Algorithms - Health Checks
LB should only forward traffic to “healthy” backend servers.

* **Least Connection Method** — This method directs traffic to the server with the fewest active connections. This approach is quite useful when there are a large number of persistent client connections which are unevenly distributed between the servers.
* **Least Response Time Method** — This algorithm directs traffic to the server with the fewest active connections and the lowest average response time.
* **Least Bandwidth Method** - This method selects the server that is currently serving the least amount of traffic measured in megabits per second (Mbps).
* **Round Robin Method** — This method cycles through a list of servers and sends each new request to the next server. When it reaches the end of the list, it starts over at the beginning. It is most useful when the servers are of equal specification and there are not many persistent connections.
* **Weighted Round Robin Method** — The weighted round-robin scheduling is designed to better handle servers with different processing capacities. Each server is assigned a weight (an integer value that indicates the processing capacity). Servers with higher weights receive new connections before those with less weights and servers with higher weights get more connections than those with less weights.
* **IP Hash** — Under this method, a hash of the IP address of the client is calculated to redirect the request to a server.