import { Controller, Get, Post } from '@nestjs/common';
import { NodeDiscoveryService } from './node_discovery.service';
import { GrpcMethod } from "@nestjs/microservices";
import { Agent, AgentStatus, AgentStore, RegisterAgentRequest, RegisterAgentResponse, DeregisterAgentRequest, DeregisterAgentResponse, HeartbeatRequest, HeartbeatResponse, GetAgentsRequest, GetAgentsResponse, GetPeersRequest, GetPeersResponse, GetAgentStatusRequest, GetAgentStatusResponse, UpdateAgentMetadataRequest, UpdateAgentMetadataResponse } from './node_discovery.types';

@Controller()
export class NodeDiscoveryController {
  constructor(private readonly nodeDiscoveryService: NodeDiscoveryService) {}

  @Get('hello')
  getHello(): string {
    return "Hello World!";
  }


  @GrpcMethod('NodeDiscoveryService', 'Test')
  getTest(): { message: string } { return this.nodeDiscoveryService.getTest(); }

  @GrpcMethod('NodeDiscoveryService', 'RegisterNode')
  registerAgent(request: RegisterAgentRequest): RegisterAgentResponse {

    const { id, address, port } = request;

    if (!id || !address || !port) {
      return { success: false, message: 'Invalid request: Missing id, address, or port.' };
    }

    return this.nodeDiscoveryService.registerNode(id, address, port);
  }

  @GrpcMethod('NodeDiscoveryService', 'DeregisterNode')
  deregisterAgent(request: DeregisterAgentRequest): DeregisterAgentResponse {
    const { id } = request;

    if (!id) {
        return { success: false, message: 'Invalid request: Missing id.' };
    }

    return this.nodeDiscoveryService.deregisterNode(id);
  }

  @GrpcMethod('NodeDiscoveryService', 'Heartbeat')
  heartbeat(request: HeartbeatRequest): HeartbeatResponse {
    const { id } = request;

    if (!id) {
        return { success: false, message: 'Invalid request: Missing id.' };
    }

    return this.nodeDiscoveryService.heartbeat(id);
  }

  @GrpcMethod('NodeDiscoveryService', 'GetPeers')
  getPeers(request: GetPeersRequest): GetPeersResponse {
    const { id } = request;

    if (!id) {
        return { success: false, message: 'Invalid request: Missing id.' };
    }

    return this.nodeDiscoveryService.heartbeat(id);
  }

  @GrpcMethod('NodeDiscoveryService', 'GetNodes')
  getAgents(request: GetAgentsRequest): GetAgentsResponse {
    return this.nodeDiscoveryService.getNodes();
  }

  @GrpcMethod('NodeDiscoveryService', 'GetNodeStatus')
  getAgentStatus(request: GetAgentStatusRequest): GetAgentStatusResponse {
    const { id } = request;
    return this.nodeDiscoveryService.getNodeStatus(id);
  }

  @GrpcMethod('NodeDiscoveryService', 'UpdateNodeMetadata')
  updateAgentMetadata(request: UpdateAgentMetadataRequest): UpdateAgentMetadataResponse {
    return this.nodeDiscoveryService.updateNodeMetadata();
  }
}
