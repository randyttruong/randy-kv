import { Controller, Get, Post } from '@nestjs/common';
import { NodeDiscoveryService } from './node_discovery.service';
import { GrpcMethod } from "@nestjs/microservices";

@Controller()
export class NodeDiscoveryController {
  constructor(private readonly nodeDiscoveryService: NodeDiscoveryService) {}

  @Get('hello')
  getHello(): string {
    return "Hello World!";
  }


  @GrpcMethod('NodeDiscoveryService', 'Test')
  getTest(): { message: string } {
    return { message: 'Test' };
  }

  @GrpcMethod('NodeDiscoveryService', 'RegisterNode')
  registerNode(): void {}

  @GrpcMethod('NodeDiscoveryService', 'DeregisterNode')
  deregisterNode(): void {}

  @GrpcMethod('NodeDiscoveryService', 'Heartbeat')
  heartbeat(): void {}

  @GrpcMethod('NodeDiscoveryService', 'GetPeers')
  getPeers(): void {}

  @GrpcMethod('NodeDiscoveryService', 'GetNodes')
  getNodes(): void {}

  @GrpcMethod('NodeDiscoveryService', 'GetNodeStatus')
  getNodeStatus(): void {}

  @GrpcMethod('NodeDiscoveryService', 'UpdateNodeMetadata')
  updateNodeMetadata(): void {}
}
