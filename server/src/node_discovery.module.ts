import { Module } from '@nestjs/common';
import { NodeDiscoveryController } from './node_discovery.controller';
import { NodeDiscoveryService } from './node_discovery.service';

@Module({
  imports: [],
  controllers: [NodeDiscoveryController],
  providers: [NodeDiscoveryService],
})
export class NodeDiscoveryModule {}
