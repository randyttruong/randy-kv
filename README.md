# Randy-KV
Distributed, in-memory key-value database in C++ that utilizes randomized hashing for effective load balancing. 


# Architecture 
RandyKV is built on top of a **gossip-based communication protocol**. As such, it requires **nodes** that exchange data with aid from a **node discovery service**. In RandyKV, there is a single type of **node**, called an agent, that is able to participate in the system by both sending (`push`ing) and receiving (`pull`ing) data. 

In order to participate in the system, an `agent` must communicate with the **node discovery service**, which is a backend service that maintains global state of all participating nodes in the system. 

- Agents, which maintain central database logic, are implemented using C++
- Node discovery, which maintains global state of all existing nodes, is implemented in TypeScript (NestJS), using Google's gRPC. 
