import { Injectable } from '@nestjs/common';
import {
  Agent,
  AgentStatus,
  AgentStore,
  DeregisterAgentResponse, GetAgentsRequest, GetPeersResponse,
  HeartbeatResponse,
  RegisterAgentResponse,
  GetAgentsResponse, GetAgentStatusRequest, GetAgentStatusResponse, UpdateAgentMetadataResponse
} from "./node_discovery.types";

@Injectable()
export class NodeDiscoveryService {

  private nodes: AgentStore = {};

  getTest(): { message: string } { return { message: 'Test' }  }

  registerNode(id: string, address: string, port: number): RegisterAgentResponse {
    const newNode: Agent = new Agent(id, address, port, AgentStatus.HEALTHY, Date.now().toString());

    this.nodes[id] = newNode;

    return { success: true, message: 'Node registered.' }
  }

  deregisterNode(id: string): DeregisterAgentResponse {
    return { success: true, message: 'Node deregistered.' }
  }

  heartbeat(id: string): HeartbeatResponse {

    if (this.nodes[id]) {
      this.nodes[id].setLastHeartbeat(Date.now().toString());
      return { success: true, message: 'Heartbeat received.' }
    }

    return { success: false, message: 'Node not found.' }
  }

  getPeers(id: string): GetPeersResponse {
    // TODO: Implement this method
    return { success: true, message: 'Peers found.' }
  }
  getNodes(): GetAgentsResponse {
    // TODO: Implement this method
    return { success: true, message: 'Nodes found.' }
  }
  getNodeStatus(id: string): GetAgentStatusResponse {
    // TODO: Implement this method
    return { success: true, message: 'Node status found.', status: AgentStatus.HEALTHY}
  }
  updateNodeMetadata(): UpdateAgentMetadataResponse {
    // TODO: Implement this method
    return { success: true, message: 'Node metadata updated.' }
  }
}